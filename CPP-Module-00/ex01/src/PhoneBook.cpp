/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:53:04 by welepy            #+#    #+#             */
/*   Updated: 2025/04/07 22:42:02 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void  PhoneBook::Add(void)
{
	std::cout << "Adding new contact:" << std::endl;

	std::cout << "What's their first name? " << std::endl;
	getline(std::cin, contacts[this->index].first_name);

	std::cout << "What's their last name? " << std::endl;
	getline(std::cin, contacts[this->index].last_name);

	std::cout << "What's their nickname? " << std::endl;
	getline(std::cin, contacts[this->index].nickname);

	std::cout << "What's their phone number? " << std::endl;
	getline(std::cin, contacts[this->index].phone_number);

	std::cout << "What's their darkest secret? " << std::endl;
	getline(std::cin, contacts[this->index].darkest_secret);

	std::cout << "Finished!\n" << std::endl;
	this->index++;

	if (this->index == 8)
	{
		this->index = 0;
		this->is_full = true;
	}
}
void  PhoneBook::exiting(void)
{
	std::cout << "Exiting" << std::endl;
	exit(0);
}

void  PhoneBook::Search(void)
{
	std::string	input;


	if (this->index == 0)
	{
		std::cout << "\033[31mAdd at least one contact before searching.\033[0m" << std::endl;
		return ;
	}

	std::cout << "Which contact index i should show you\nIndex: ";
	while (!(getline(std::cin, input)))
	{
		if (std::cin.eof())
			this->exiting();
		if (input.empty() || !isdigit(input[0]) || atoi(std::string::c_str(input)) < 1 || atoi(std::string::c_str(input)) > 8)
		{
			std::cin.clear();
			std::cout << "\033[31mOnly digits in range of 1 to 8 are allowed.\033[0m\n";
			std::cout << "Which contact index i should show you\nIndex: ";
		}
		else if (stoi(input) - 1 >= this->index && this->is_full == false)
		{
			std::cout << "\033[33mYou only have " << this->index << " Contacts saved.\033[0m" << std::endl;
			std::cin.clear();
			std::cout << "Which contact index i should show you\nIndex: ";
		}
	}
	index = atoi(input.c_str());
	if (index > 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	//	this->contacts[index - 1].get_contact(index);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	return ;
}
