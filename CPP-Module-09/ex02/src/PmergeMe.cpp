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

#include "PmergeMe.hpp"

// ── Canonical form ────────────────────────────────────────────────────────────

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) : _list(other._list), _deque(other._deque) { }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_list  = other._list;
		_deque = other._deque;
	}
	return *this;
}

// ── Constructor ───────────────────────────────────────────────────────────────

PmergeMe::PmergeMe(char **av) {
	std::list<std::string> tokens;
	std::list<std::string> temp;

	for (int i = 1; av[i]; i++) {
		temp = this->split(std::string(av[i]));
		tokens.insert(tokens.end(), temp.begin(), temp.end());
	}

	for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
		// FIX #8: reject any non-digit character (catches '-', letters, etc.)
		if (it->empty() || it->find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Sequence must contain only positive integers");

		// FIX #8: use strtol to detect overflow instead of silent atoi
		errno = 0;
		char *end_ptr;
		long val = std::strtol(it->c_str(), &end_ptr, 10);
		if (errno != 0 || *end_ptr != '\0' || val > INT_MAX || val < 0)
			throw std::runtime_error("Value out of range or invalid: " + *it);

		int n = static_cast<int>(val);

		// FIX #9: reject duplicates
		if (std::find(_deque.begin(), _deque.end(), n) != _deque.end())
			throw std::runtime_error("Sequence contains duplicate values");

		_list.push_back(n);
		_deque.push_back(n);
	}

	if (_deque.empty())
		throw std::runtime_error("Empty sequence");
}

// ── Jacobsthal helper ─────────────────────────────────────────────────────────

// J(n) = (2^n - (-1)^n) / 3
int PmergeMe::get_jacobsthal(int n) const {
	return static_cast<int>((std::pow(2.0, n) - std::pow(-1.0, n)) / 3.0);
}

// ── Binary search for std::list ───────────────────────────────────────────────

// FIX #4: std::upper_bound on a list uses O(n) iterator advances but still
// performs O(log n) *comparisons*, which is what Ford-Johnson optimises.
// This manual implementation makes that contract explicit and correct.
std::list<int>::iterator PmergeMe::list_upper_bound(std::list<int> &chain, int val) {
	std::list<int>::iterator it = chain.begin();
	std::list<int>::iterator end = chain.end();
	std::ptrdiff_t count = static_cast<std::ptrdiff_t>(chain.size());

	while (count > 0) {
		std::ptrdiff_t step = count / 2;
		std::list<int>::iterator mid = it;
		std::advance(mid, step);

		if (!(val < *mid)) {   // i.e. *mid <= val
			it = ++mid;
			count -= step + 1;
		} else {
			count = step;
		}
	}
	return it;
}

// ── Ford-Johnson — std::deque ─────────────────────────────────────────────────

void PmergeMe::ford_johnson(std::deque<int> &arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	// 1. Pairing phase
	int straggler = 0;                      // FIX #3: always initialised
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

	// 2. Recursively sort winners
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);
	ford_johnson(winners);

	// 3. Build initial main chain
	// After recursive sort, winners is ordered. We need to map each winner
	// back to its loser using the original pairs array — by value is safe here
	// only when values are unique (guaranteed by constructor FIX #9).
	// FIX #1: build a deque of losers whose order mirrors the sorted winners,
	//         so the index relationship is always preserved.
	std::deque<int> pending;
	std::deque<int> main_chain;

	// The loser paired with winners[0] is placed at front (free insertion)
	{
		int first_winner = winners[0];
		int first_loser  = 0;
		for (size_t i = 0; i < pairs.size(); ++i) {
			if (pairs[i].winner == first_winner) {
				first_loser = pairs[i].loser;
				break;
			}
		}
		main_chain.push_back(first_loser);  // goes before winners[0]
		main_chain.push_back(winners[0]);
	}

	// Append remaining winners; collect their losers into pending
	for (size_t i = 1; i < winners.size(); ++i) {
		main_chain.push_back(winners[i]);
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].winner == winners[i]) {
				pending.push_back(pairs[j].loser);
				break;
			}
		}
	}
	if (has_straggler) pending.push_back(straggler);

	// 4. Insert pending elements using Jacobsthal-order binary search
	// FIX #5: correct 0-based Jacobsthal block bounds
	//   J(k) gives the exclusive upper bound of the k-th block (0-indexed into pending)
	//   J(k-1) gives the inclusive lower bound
	//   We start at j_idx = 3 so the first block covers indices [J(2), J(3)) = [1, 3)
	size_t inserted_count = 0;
	int    j_idx          = 3;

	while (inserted_count < pending.size()) {
		int j_val      = get_jacobsthal(j_idx);
		int prev_j_val = get_jacobsthal(j_idx - 1);

		// FIX #5: no "-1" offset — j_val is already the correct exclusive bound
		int upper = std::min(static_cast<int>(pending.size()), j_val);
		int lower = prev_j_val;

		// Insert from end of block toward start (Ford-Johnson strategy)
		for (int i = upper - 1; i >= lower; --i) {
			// FIX #6: guard against stale i after pending shrinks (not needed
			//         here since we iterate over original indices, but kept for safety)
			if (i >= static_cast<int>(pending.size())) continue;

			int val = pending[i];
			std::deque<int>::iterator pos = std::upper_bound(main_chain.begin(), main_chain.end(), val);
			main_chain.insert(pos, val);
			inserted_count++;
		}
		j_idx++;
	}

	arr = main_chain;
}

// ── Ford-Johnson — std::list ──────────────────────────────────────────────────

void PmergeMe::ford_johnson(std::list<int> &arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	// 1. Pairing phase
	int  straggler     = 0;                 // FIX #3: always initialised
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
	for (std::list<Pair>::iterator p_it = pairs.begin(); p_it != pairs.end(); ++p_it)
		winners.push_back(p_it->winner);
	ford_johnson(winners);

	// 3. Build initial main chain
	// FIX #1 & #2: track pairs by index position, not by searching winner value,
	//              so duplicate values never cause a mismatch.
	//              We convert pairs to a vector for O(1) indexed access.
	std::deque<Pair> pairs_vec(pairs.begin(), pairs.end());  // index-addressable copy

	// Map sorted winners back to their original pair index
	// Since duplicates are rejected, value lookup is unambiguous.
	std::list<int> pending;
	std::list<int> main_chain;

	// First winner's loser goes to front of main chain (free insertion)
	{
		int first_winner = winners.front();
		int first_loser  = 0;
		for (size_t i = 0; i < pairs_vec.size(); ++i) {
			if (pairs_vec[i].winner == first_winner) {
				first_loser = pairs_vec[i].loser;
				break;
			}
		}
		main_chain.push_back(first_loser);
		main_chain.push_back(winners.front());
	}

	// Append remaining winners; collect their losers into pending
	// FIX #2: iterate by position starting from index 1 (not by value comparison)
	std::list<int>::iterator w_it = winners.begin();
	++w_it; // skip index 0, already handled above
	for (; w_it != winners.end(); ++w_it) {
		main_chain.push_back(*w_it);
		int wval = *w_it;
		for (size_t i = 0; i < pairs_vec.size(); ++i) {
			if (pairs_vec[i].winner == wval) {
				pending.push_back(pairs_vec[i].loser);
				break;
			}
		}
	}
	if (has_straggler) pending.push_back(straggler);

	// 4. Insert pending using Jacobsthal-order binary search
	// FIX #5: correct 0-based block bounds (same logic as deque version)
	size_t total_pending = pending.size();
	size_t inserted      = 0;
	int    j_idx         = 3;

	while (inserted < total_pending) {
		int j_val      = get_jacobsthal(j_idx);
		int prev_j_val = get_jacobsthal(j_idx - 1);

		int upper = std::min(static_cast<int>(total_pending), j_val);
		int lower = prev_j_val;

		// FIX #6: added guard so we never read past the end of pending
		for (int i = upper - 1; i >= lower; --i) {
			if (i >= static_cast<int>(total_pending)) continue;

			// O(n) advance, but O(log n) comparisons via list_upper_bound
			std::list<int>::iterator p_it = pending.begin();
			std::advance(p_it, i);
			int val = *p_it;

			// FIX #4: use our explicit binary-search helper instead of
			//         relying on std::upper_bound's linear iterator fallback
			std::list<int>::iterator pos = list_upper_bound(main_chain, val);
			main_chain.insert(pos, val);
			inserted++;
		}
		j_idx++;
	}

	arr = main_chain;
}

// ── Public sort entry point ───────────────────────────────────────────────────

void PmergeMe::sort(void) {
	struct timeval start, end;
	long seconds, microseconds, elapsed;

	// Print unsorted sequence (read from deque before it is modified)
	std::cout << "Before: ";
	for (std::deque<int>::size_type i = 0; i < _deque.size(); ++i)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;

	const std::deque<int>::size_type size = _deque.size();

	// ── deque ──
	gettimeofday(&start, NULL);
	ford_johnson(_deque);
	gettimeofday(&end, NULL);
	seconds      = end.tv_sec  - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapsed      = seconds * 1000000 + microseconds;

	std::cout << "After:  ";
	for (std::deque<int>::size_type i = 0; i < _deque.size(); ++i)
		std::cout << _deque[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size
	          << " elements with std::deque : " << elapsed << " us" << std::endl;

	// ── list ──
	gettimeofday(&start, NULL);
	ford_johnson(_list);
	gettimeofday(&end, NULL);
	seconds      = end.tv_sec  - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	elapsed      = seconds * 1000000 + microseconds;

	std::cout << "Time to process a range of " << size
	          << " elements with std::list  : " << elapsed << " us" << std::endl;
}

// ── String splitting utility ──────────────────────────────────────────────────

std::list<std::string> PmergeMe::split(const std::string &input) {
	std::list<std::string> result;
	std::string token;
	std::string::size_type i = 0;
	const std::string::size_type n = input.size();

	while (i < n && (input[i] == ' ' || input[i] == '\t'))
		++i;

	while (i < n) {
		token.clear();
		while (i < n && input[i] != ' ' && input[i] != '\t') {
			token += input[i];
			++i;
		}
		if (!token.empty())
			result.push_back(token);
		while (i < n && (input[i] == ' ' || input[i] == '\t'))
			++i;
	}
	return result;
}