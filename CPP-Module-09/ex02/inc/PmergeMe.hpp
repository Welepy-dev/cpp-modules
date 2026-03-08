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
# include <cmath>
# include <cstddef>
# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <sys/time.h>

// Estrutura para manter a relação entre o vencedor e seu respectivo perdedor
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
		int							get_jacobsthal(int n) const;
		void						sortList(void);
};

//ford-johnson also called merge-insert, reduces the number of comparisons by not focusing on moves or swaps
//1. divide the n elements in pairs, if it has a odd number, one number is hold alone
//2. compare each pair and identify the (winners) biggest and the (losers)smallest ones
//3. take all winners of each pair and organize them recursively using the ford-johnson algorithm, creating a main sequence called main chain
//4. on the losers' side to minimize comparisons we insert in linear order, based on the jacobsthal sequence
//4.1 the jacobsthal sequence
#endif
