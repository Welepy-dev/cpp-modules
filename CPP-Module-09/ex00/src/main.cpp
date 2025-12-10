/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:36:46 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/07 11:38:21 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main (int argc, char **argv) {
	const char *csv = "data.csv";
	if (argc != 2) {
		std::cout << "Wrong input" << std::endl << "Right input: ./btc file." << std::endl;
		return (0);
	}
	try {
		BitcoinExchange btc(csv, argv[1]);
	}	catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
	return (0);
}
