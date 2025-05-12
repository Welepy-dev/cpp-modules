/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:09:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/10 14:35:45 by marcsilv         ###   ########.fr       */
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
	return (fixed_point);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(fixed_point) / (1 << bits);
}


float	Fixed::toInt(void) const
{
	return fixed_point >> bits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (fixed_point < other.fixed_point);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (fixed_point >= other.fixed_point);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (fixed_point != other.fixed_point);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
} //we do not return references because we want to create new independent values, not modifying existing ones

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;

	res.setRawBits((this->getRawBits() / 256) * other.getRawBits());
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;

	res.setRawBits((this->getRawBits() * 256) / other.getRawBits());
	return (res);
}

Fixed &Fixed::operator++(void)
{
	fixed_point++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	fixed_point--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

