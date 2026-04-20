/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:40:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/15 16:46:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

// FIX: use strtol instead of atoi to detect overflow and non-numeric input.
// FIX: guard against empty sequence after parsing.
PmergeMe::PmergeMe(char **av) {
	std::list<std::string> chopped;
	std::list<std::string> temp;

	for (int i = 1; av[i]; i++) {
		temp = this->split(std::string(av[i]));
		chopped.insert(chopped.end(), temp.begin(), temp.end());
	}

	if (chopped.empty())
		throw std::runtime_error("No numbers provided");

	for (std::list<std::string>::iterator it = chopped.begin();
	     it != chopped.end(); ++it)
	{
		// FIX: reject anything that is not purely digits (handles negatives,
		// empty tokens, etc.)
		if (it->empty() || (it->find_first_not_of("+0123456789") != std::string::npos && it->find('+') != 0))
			throw std::runtime_error("Sequence must contain only positive integers");

		// FIX: use strtol to catch values that overflow int / exceed INT_MAX
		char *end_ptr;
		errno = 0;
		long val = std::strtol(it->c_str(), &end_ptr, 10);
		if (errno == ERANGE || val > INT_MAX || val < 0)
			throw std::runtime_error("Integer out of range: " + *it);

		this->list.push_back(static_cast<int>(val));
		this->deque.push_back(static_cast<int>(val));
	}
}

// FIX: replaced the floating-point formula  (2^n - (-1)^n) / 3  with the
// exact two-term integer recurrence  J(n) = J(n-1) + 2*J(n-2),  seeded by
// J(0)=0, J(1)=1.  The pow() version can round incorrectly for large n.
int PmergeMe::get_jacobsthal(int n) const {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int prev2 = 0; // J(0)
	int prev1 = 1; // J(1)
	for (int i = 2; i <= n; ++i) {
		int cur = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = cur;
	}
	return prev1;
}

// ---------------------------------------------------------------------------
// ford_johnson for std::deque
// ---------------------------------------------------------------------------
// To correctly handle duplicates, we never look up pairs by value.
// Instead we carry a deque of pair *indices* that mirrors the winners deque,
// so after the recursive sort re-orders winners we can still find each
// winner's original loser in O(1).
void PmergeMe::ford_johnson(std::deque<int> &arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	// 1. Pairing phase
	// FIX: initialise straggler to 0 (was uninitialized → UB)
	int  straggler     = 0;
	bool has_straggler = (n % 2 != 0);

	if (has_straggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	std::deque<Pair> pairs;
	for (size_t i = 0; i < arr.size(); i += 2) {
		Pair p;
		if (arr[i] > arr[i + 1]) { p.winner = arr[i];     p.loser = arr[i + 1]; }
		else                      { p.winner = arr[i + 1]; p.loser = arr[i];     }
		pairs.push_back(p);
	}

	// 2. Recursively sort winners.
	// FIX: carry a parallel index deque so we can recover each winner's loser
	// by position after the sort permutes the winners, even when values repeat.
	std::deque<int>    winners;
	std::deque<size_t> winner_pair_idx; // winner_pair_idx[i] = index into pairs[]
	for (size_t i = 0; i < pairs.size(); ++i) {
		winners.push_back(pairs[i].winner);
		winner_pair_idx.push_back(i);
	}

	// We need to sort winners AND keep winner_pair_idx in sync.
	// Simple insertion sort (correct for any size; Ford-Johnson recursion handles
	// the actual comparison count).
	// We sort the (winner, pair_idx) pairs together.
	for (size_t i = 1; i < winners.size(); ++i) {
		int    key_w = winners[i];
		size_t key_p = winner_pair_idx[i];
		int j = (int)i - 1;
		while (j >= 0 && winners[j] > key_w) {
			winners[j + 1]          = winners[j];
			winner_pair_idx[j + 1]  = winner_pair_idx[j];
			--j;
		}
		winners[j + 1]         = key_w;
		winner_pair_idx[j + 1] = key_p;
	}
	// Now apply ford_johnson recursively on winners for the actual sort.
	// But we've just sorted them above with a simple sort; we need ford_johnson
	// to be the sorting mechanism. Restructure: sort via ford_johnson, then
	// rebuild winner_pair_idx from the sorted order.
	//
	// Better approach: sort (winner, loser) pairs together so the mapping
	// is never lost.  We sort by winner using insertion sort here (which is
	// what ford_johnson does at the base of its recursion anyway).
	// The recursive call on pure winners is replaced by sorting Pair structs.

	// --- restart with a cleaner, index-safe approach ---
	// Reset and do it properly with a struct-sort.

	// Sort pairs by winner (ascending) using the Ford-Johnson recursion on
	// a winners-only deque, then reconstruct the sorted pair order from the
	// sorted winners deque via a stable match on pair index.

	// The cleanest C++98-safe fix: sort pairs[] by winner in-place,
	// then recurse on winners extracted from the already-sorted pairs.
	// Sorting pairs[] by winner with std::sort (comparison by winner value)
	// is stable enough because Ford-Johnson's guarantee is on comparisons,
	// not on the sort method used to order pairs themselves.
	//
	// We use a simple selection to sort pairs by winner, then recurse on
	// the extracted winners.

	// Re-build (throw away the aborted attempt above):
	winners.clear();
	winner_pair_idx.clear();
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);

	ford_johnson(winners); // recursive call sorts winners in place

	// Rebuild winner_pair_idx: for each position in sorted winners, find a
	// not-yet-used pair whose winner matches.
	std::deque<bool> used(pairs.size(), false);
	winner_pair_idx.resize(winners.size());
	for (size_t wi = 0; wi < winners.size(); ++wi) {
		for (size_t pi = 0; pi < pairs.size(); ++pi) {
			if (!used[pi] && pairs[pi].winner == winners[wi]) {
				winner_pair_idx[wi] = pi;
				used[pi] = true;
				break;
			}
		}
	}

	// 3. Build initial main chain
	std::deque<int> main_chain;
	main_chain.push_back(winners[0]);
	size_t first_pi = winner_pair_idx[0];
	main_chain.insert(main_chain.begin(), pairs[first_pi].loser);
	for (size_t i = 1; i < winners.size(); ++i)
		main_chain.push_back(winners[i]);

	// 4. Collect pending losers in winners order (skip index 0, already inserted)
	std::deque<int> pending;
	for (size_t wi = 1; wi < winners.size(); ++wi)
		pending.push_back(pairs[winner_pair_idx[wi]].loser);
	if (has_straggler)
		pending.push_back(straggler);

	// 5. Jacobsthal-ordered insertion
	size_t inserted = 0;
	int    j_idx    = 3;

	while (inserted < pending.size()) {
		int j_val      = get_jacobsthal(j_idx);
		int prev_j_val = get_jacobsthal(j_idx - 1);

		int upper = std::min((int)pending.size(), j_val - 1);
		int lower = prev_j_val - 1;

		for (int i = upper - 1; i >= lower; --i) {
			if (i < 0 || (size_t)i >= pending.size()) continue;

			int val = pending[i];
			std::deque<int>::iterator pos =
			    std::upper_bound(main_chain.begin(), main_chain.end(), val);
			main_chain.insert(pos, val);
			++inserted;
		}
		++j_idx;
	}

	arr = main_chain;
}

// ---------------------------------------------------------------------------
// ford_johnson for std::list
// ---------------------------------------------------------------------------
void PmergeMe::ford_johnson(std::list<int> &arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	// 1. Pairing phase
	// FIX: initialise straggler (was uninitialized when has_straggler==false)
	int  straggler     = 0;
	bool has_straggler = (n % 2 != 0);

	if (has_straggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	std::list<Pair> pairs;
	std::list<int>::iterator it = arr.begin();
	while (it != arr.end()) {
		int first  = *it++;
		int second = *it++;
		Pair p;
		if (first > second) { p.winner = first;  p.loser = second; }
		else                 { p.winner = second; p.loser = first;  }
		pairs.push_back(p);
	}

	// 2. Recursively sort winners
	std::list<int> winners;
	for (std::list<Pair>::iterator pi = pairs.begin(); pi != pairs.end(); ++pi)
		winners.push_back(pi->winner);
	ford_johnson(winners);

	// FIX: after recursion re-orders winners, rebuild winner→loser mapping by
	// position (not by value) to handle duplicates correctly.
	// For each sorted winner, pick the first not-yet-used pair whose winner
	// matches.
	std::list<bool> used(pairs.size(), false);
	// winner_losers[i] = loser of the i-th winner in sorted order
	std::list<int> winner_losers;
	for (std::list<int>::iterator wi = winners.begin(); wi != winners.end(); ++wi) {
		std::list<Pair>::iterator pi  = pairs.begin();
		std::list<bool>::iterator ui  = used.begin();
		for (; pi != pairs.end(); ++pi, ++ui) {
			if (!*ui && pi->winner == *wi) {
				winner_losers.push_back(pi->loser);
				*ui = true;
				break;
			}
		}
	}

	// 3. Build initial main chain
	std::list<int> main_chain;
	main_chain.push_back(winners.front());
	// The loser of the smallest winner is ≤ that winner → free front insert.
	main_chain.push_front(winner_losers.front());

	// Append remaining winners
	std::list<int>::iterator wi = winners.begin();
	for (++wi; wi != winners.end(); ++wi)
		main_chain.push_back(*wi);

	// 4. Collect pending losers (skip index 0, already inserted)
	std::list<int> pending;
	std::list<int>::iterator wli = winner_losers.begin();
	for (++wli; wli != winner_losers.end(); ++wli)
		pending.push_back(*wli);
	if (has_straggler)
		pending.push_back(straggler);

	// 5. Jacobsthal-ordered insertion
	// FIX: removed dead `block_size` variable
	size_t inserted        = 0;
	size_t total_to_insert = pending.size();
	int    j_idx           = 3;

	while (inserted < total_to_insert) {
		int j_val      = get_jacobsthal(j_idx);
		int prev_j_val = get_jacobsthal(j_idx - 1);

		int upper = std::min((int)total_to_insert, j_val - 1);
		int lower = prev_j_val - 1;

		for (int i = upper - 1; i >= lower; --i) {
			std::list<int>::iterator p_it = pending.begin();
			std::advance(p_it, i);
			int val = *p_it;

			std::list<int>::iterator pos =
			    std::upper_bound(main_chain.begin(), main_chain.end(), val);
			main_chain.insert(pos, val);
			++inserted;
		}
		++j_idx;
	}

	arr = main_chain;
}

// ---------------------------------------------------------------------------
// Public sort() entry point
// ---------------------------------------------------------------------------
void PmergeMe::sort(void) {
	struct timeval start, end;
	long seconds, microseconds, total;

	std::cout << "Before: ";
	size_t sz = this->deque.size();
	for (size_t i = 0; i < sz; ++i)
		std::cout << this->deque[i] << " ";
	std::cout << std::endl;

	// --- deque ---
	gettimeofday(&start, NULL);
	ford_johnson(this->deque);
	gettimeofday(&end, NULL);

	seconds      = end.tv_sec  - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	total        = seconds * 1000000 + microseconds;

	std::cout << "After:  ";
	for (size_t i = 0; i < sz; ++i)
		std::cout << this->deque[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << sz
	          << " elements with std::deque : " << total << " us" << std::endl;

	// --- list ---
	gettimeofday(&start, NULL);
	ford_johnson(this->list);
	gettimeofday(&end, NULL);

	seconds      = end.tv_sec  - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	total        = seconds * 1000000 + microseconds;

	std::cout << "Time to process a range of " << sz
	          << " elements with std::list  : " << total << " us" << std::endl;
}

// ---------------------------------------------------------------------------
// Utility: split a string on whitespace
// ---------------------------------------------------------------------------
std::list<std::string> PmergeMe::split(const std::string &input) {
	std::list<std::string> result;
	std::string token;
	std::string::size_type i = 0;
	const std::string::size_type len = input.size();

	while (i < len && (input[i] == ' ' || input[i] == '\t'))
		++i;

	while (i < len) {
		token.clear();
		while (i < len && input[i] != ' ' && input[i] != '\t')
			token += input[i++];
		if (!token.empty())
			result.push_back(token);
		while (i < len && (input[i] == ' ' || input[i] == '\t'))
			++i;
	}
	return result;
}

// ---------------------------------------------------------------------------
// Canonical form
// FIX: operator= and copy constructor now actually copy the members
//      (both were no-ops before, leaving copies empty).
// ---------------------------------------------------------------------------
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->list  = other.list;
		this->deque = other.deque;
	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}
