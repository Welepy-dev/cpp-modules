/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:24:00 by welepy            #+#    #+#             */
/*   Updated: 2025/03/26 20:43:33 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "../inc/PhoneBook.hpp"

using namespace std;


int	main(void)
{
	PhoneBook phonebook;
	string	  input;
	int	  is_finished = 1;

	phonebook.index = 0;

	std::cout << "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" << endl; 
	while (is_finished && getline(cin, input))
	{
		if (std::cin.eof() == true)
			phonebook.exiting();
		if (input.compare("ADD") == 0)
			phonebook.Add();
		if (input.compare("EXIT") == 0)
			phonebook.exiting();
		if (input.compare("SEARCH") == 0)
			phonebook.Search();
		else
            cout << "Invalid command! Try again." << endl;
		std::cout << "\033[33mWrite your command, [ADD, SEARCH, EXIT]\033[0m" << endl; 
	}
	return (0);
}
