/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:53:04 by welepy            #+#    #+#             */
/*   Updated: 2025/04/15 18:01:55 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/PhoneBook.hpp"
#include	"../inc/utils.hpp"

#include	<iomanip>
#include	<iostream>
#include	<cstdlib>

PhoneBook::PhoneBook(void)
{
	index = 0;
	is_full = false;
}

PhoneBook::~PhoneBook(void) { }

void	PhoneBook::add(void)
{
	std::string	input;
	
	std::cout << "Adding new contact:" << std::endl;

	std::cout << "What's their first name? " << std::endl;
	getline(std::cin, input);
	contacts[index].setFirstName(input);

	std::cout << "What's their last name? " << std::endl;
	getline(std::cin, input);
	contacts[index].setLastName(input);

	std::cout << "What's their nickname? " << std::endl;
	getline(std::cin, input);
	contacts[index].setNickname(input);

	std::cout << "What's their phone number? " << std::endl;
	getline(std::cin, input);
	contacts[index].setPhoneNumber(input);

	std::cout << "What's their darkest secret? " << std::endl;
	getline(std::cin, input);
	contacts[index].setDarkestSecret(input);

	std::cout << "Finished!\n" << std::endl;
	index++;

	if (index == 8)
	{
		index = 0;
		is_full = true;
	}
}
void  PhoneBook::exiting(void)
{
	std::cout
				<< "Exiting" <<
	std::endl;

	exit(0);
}
void	PhoneBook::getContactInfo(int index)
{
	std::cout
				<< "|" << std::setw(10)
				<< (1 + index)
				<< "|" << std::setw(10)
				<< contacts[index].getFirstName()
				<< "|" << std::setw(10)
				<< contacts[index].getLastName()
				<< "|" << std::setw(10)
				<< contacts[index].getNickname()
				<< "|" <<
	std::endl;
}

void	PhoneBook::search(void)
{
	std::string	input;

	if (index == 0 && !is_full)
	{
		std::cout
					<< "\033[31mAdd at least one contact before searching.\033[0m" <<
		std::endl;
		return ;
	}

	std::cout << "Which contact of index i should show you\nIndex: ";
	while (1 && getline(std::cin, input))
	{
		
		if (std::cin.eof())
			exiting();
		if (!isAllNum(strtrim(input)) || atoi(strtrim(input).c_str()) < 1 || atoi(strtrim(input).c_str()) > 8)
		{
			std::cin.clear();
			std::cout << "\033[31mOnly digits in range of 1 to 8 are allowed.\033[0m\n";
			std::cout << "Which contact index i should show you\nIndex: ";
		}
		else if (atoi(strtrim(input).c_str()) > index && is_full == false)
		{
			if (atoi(strtrim(input).c_str()) == 1)
			std::cout
						<< "\033[33mYou only have "
						<< index << " Contact saved.\033[0m" <<
			std::endl;
			else
				std::cout
						<< "\033[33mYou only have "
						<< index << " Contacts saved.\033[0m" <<
				std::endl;
			std::cin.clear();
			std::cout << "Which contact index i should show you\nIndex: ";
		}
		else
			break ;
	}
	int search_index = atoi(strtrim(input).c_str());
	if (search_index > 0)
	{
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		getContactInfo(search_index - 1);
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	return ;
}
