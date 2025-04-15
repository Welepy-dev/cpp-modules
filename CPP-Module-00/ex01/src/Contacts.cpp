/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:31:31 by welepy            #+#    #+#             */
/*   Updated: 2025/04/15 17:42:29 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

#include <iostream>

Contact::Contact() {}
Contact::~Contact() {}

std::string	&Contact::getFirstName(void)
{
	return (first_name);
}

std::string	&Contact::getLastName(void)
{
	return (last_name);
}

std::string	&Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	&Contact::getNickname(void)
{
	return (nickname);
}

std::string	&Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}

void	Contact::setFirstName(std::string str)
{
	first_name = str;
}

void	Contact::setLastName(std::string str)
{
	last_name = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	phone_number = str;
}

void	Contact::setNickname(std::string str)
{
	nickname = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	darkest_secret = str;
}