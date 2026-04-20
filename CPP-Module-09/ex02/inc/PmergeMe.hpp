/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:32:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/15 16:40:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <cstddef>
# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <sys/time.h>
# include <cerrno>
# include <climits>
# include <cstdlib>

// Struct to maintain the relationship between winner and its respective loser
// Tracked by index to correctly handle duplicate values
typedef struct Pair_t {
	int winner;
	int loser;
} Pair;

class PmergeMe {

	public:
		~PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void						sort();

	private:
		std::list<int>				_list;
		std::deque<int>				_deque;

		void						ford_johnson(std::deque<int> &arr);
		void						ford_johnson(std::list<int> &arr);
		std::list<std::string>		split(const std::string &s);
		// FIX: replaced floating-point pow() formula with exact integer recurrence
		// to avoid rounding errors on large n.
		int							get_jacobsthal(int n) const;

		// Binary search helper for std::list (O(log n) comparisons, O(n) iterator advances)
		std::list<int>::iterator	list_upper_bound(std::list<int> &chain, int val);
};

// Ford-Johnson (merge-insert sort):
// 1. Divide n elements into pairs; hold the odd one out as straggler
// 2. Compare each pair -> identify winners (larger) and losers (smaller)
// 3. Recursively sort winners -> creates the main chain
// 4. Insert losers using Jacobsthal-order binary search to minimise comparisons

#endif