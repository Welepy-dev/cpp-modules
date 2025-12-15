/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:10:54 by codespace         #+#    #+#             */
/*   Updated: 2025/12/15 16:40:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main (int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Imprima algo valido" << std::endl;
		return (0);
	}
	try {
		PmergeMe pmergeme(argv);
		pmergeme.sort();
	}catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}
