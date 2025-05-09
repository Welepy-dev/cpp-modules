/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:09:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/09 17:21:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = n << bits;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called\n";
	fixed_point = static_cast<int>(roundf(float_value * (1 << bits)));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : fixed_point(other.fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point = other.fixed_point;
	return (*this);
}

// Getter
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (fixed_point);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called" << std::endl;
	this->fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / (1 << bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point >> bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
