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

# include <iostream>
# include <vector>
# include <cstddef>

class PmergeMe {

	public:
		~PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		
		void						sort();

	private:
		std::vector<int>			numbers;
		std::vector<std::string>	chopped_string;
		std::vector<std::string>	split(const std::string &s);

};

#endif
