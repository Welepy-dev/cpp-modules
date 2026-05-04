/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:19:55 by marcsilv          #+#    #+#             */
/*   Updated: 2026/05/04 13:19:56 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main (int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
		return (0);
	}
	try {
		PmergeMe pmergeme(argv);
		pmergeme.sort();
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
