/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:18:43 by marcsilv          #+#    #+#             */
/*   Updated: 2026/05/04 13:20:30 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Insert something valid." << std::endl;
		return (0);
	}
	try {
		RPN	rpn(argv[1]);
		rpn.calculate();
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
