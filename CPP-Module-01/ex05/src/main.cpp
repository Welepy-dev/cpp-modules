/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:01:19 by welepy            #+#    #+#             */
/*   Updated: 2025/05/05 16:13:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

#include <iostream>
#include <cstdlib>

int main()
{
	Harl	harl;

	std::cout << "Make harl say something." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "input: ";
		std::string input;
		getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cerr << "^D" << std::endl;
			exit(EXIT_FAILURE);
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
