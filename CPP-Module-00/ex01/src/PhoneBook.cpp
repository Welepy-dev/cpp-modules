/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:53:04 by welepy            #+#    #+#             */
/*   Updated: 2025/03/26 21:15:28 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
using namespace std;

void  PhoneBook::Add(void)
{
	cout << "Adding new contact:" << endl;

	cout << "What's their first name? " << endl;
	getline(cin, contacts[this->index].first_name);

	cout << "What's their last name? " << endl;
	getline(cin, contacts[this->index].last_name);

	cout << "What's their nickname? " << endl;
	getline(cin, contacts[this->index].nickname);

	cout << "What's their phone number? " << endl;
	getline(cin, contacts[this->index].phone_number);

	cout << "What's their darkest secret? " << endl;
	getline(cin, contacts[this->index].darkest_secret);

	cout << "Finished!\n" << endl;
	this->index++;

	if (this->index == 8)
	{
		this->index = 0;
		this->is_full = true;
	}
}
void  PhoneBook::exiting(void)
{
	cout << "Exiting" << endl;
	exit(0);
}

void  PhoneBook::Search(void)
{
	string	input;


	if (this->index == 0)
	{
		cout << "\033[31mAdd at least one contact before searching.\033[0m" << endl;
		return ;
	}

	cout << "Which contact index i should show you\nIndex: ";
	while (!(getline(cin, input)))
	{
		if (cin.eof())
			this->exiting();
		if (input.empty() || !isdigit(input[0]) || stoi(input) < 1 || stoi(input) > 8)
		{
			cin.clear();
			cout << "\033[31mOnly digits in range of 1 to 8 are allowed.\033[0m\n";
			cout << "Which contact index i should show you\nIndex: ";
		}
		else if (stoi(input) - 1 >= this->index && this->is_full == false)
		{
			cout << "\033[33mYou only have " << this->index << " Contacts saved.\033[0m" << endl;
			cin.clear();
			cout << "Which contact index i should show you\nIndex: ";
		}
	}
	index = atoi(input.c_str());
	if (index > 0)
	{
		cout << "|-------------------------------------------|" << endl;
		cout << "|     Index|First Name| Last Name|  Nickname|" << endl;
		cout << "|----------|----------|----------|----------|" << endl;
	//	this->contacts[index - 1].get_contact(index);
		cout << "|-------------------------------------------|" << endl;
	}
	return ;
}
