/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:24:00 by welepy            #+#    #+#             */
/*   Updated: 2025/04/15 17:42:00 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/PhoneBook.hpp"
#include "../inc/utils.hpp"

#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phonebook;
	std::string		input;
	
	std::cout	
				<< "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" << 
	std::endl; 
	while (1 && getline(std::cin, input))
	{
		if (strtrim(input) == "ADD")
			phonebook.add();
		else if (strtrim(input) == "SEARCH")
			phonebook.search();
		else if (strtrim(input) == "EXIT")
			phonebook.exiting();
		else if (std::cin.eof())
			phonebook.exiting();
		else
			std::cout << "Invalid command! Try again." << std::endl;
		std::cout
					<< "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" <<
		std::endl; 
	}
	return (0);
}
