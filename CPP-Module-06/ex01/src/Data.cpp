/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:44:12 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/19 16:11:55 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include <iostream>

void		Data::setName(std::string name) { this->name = name; }
std::string	Data::getName(void)const { return (this->name); }

void		Data::setInteger(int integer) { this->integer = integer; }
int			Data::getInteger(void)const { return (this->integer); }

Data &Data::operator=(const Data &other)
{
	std::cout << "Data's Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setInteger(other.getInteger());
	}
	return (*this);
}

Data::Data(const Data &other)
{
	std::cout << "Data's copy constructor operator called" << std::endl;

	*this = other;
}

Data::Data(int i1, int i2)
{
	std::cout << "Data's default constructor called"<< std::endl;
	name[0] = i1;
	integer = i2;
}
Data::~Data(void) { std::cout << "Data's default destructor called" << std::endl; }
