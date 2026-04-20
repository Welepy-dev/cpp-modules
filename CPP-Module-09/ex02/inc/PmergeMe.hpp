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

// Pair keeps the relationship between the larger (winner) and smaller (loser)
// of each compared pair, indexed so duplicates are handled safely.
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
		std::list<int>				list;
		std::deque<int>				deque;

		void						ford_johnson(std::deque<int> &arr);
		void						ford_johnson(std::list<int> &arr);
		std::list<std::string>		split(const std::string &s);
		// FIX: replaced floating-point pow() formula with exact integer recurrence
		// to avoid rounding errors on large n.
		int							get_jacobsthal(int n) const;
};

// Ford-Johnson (merge-insert sort):
// 1. Divide n elements into pairs; keep one straggler if n is odd.
// 2. Compare each pair → winner (larger) and loser (smaller).
// 3. Recursively sort the winners → main chain.
// 4. Insert the smallest winner's loser at the front for free (guaranteed smaller).
// 5. Insert remaining losers in Jacobsthal-order blocks using binary search,
//    each search bounded by its paired winner's current position.

#endif