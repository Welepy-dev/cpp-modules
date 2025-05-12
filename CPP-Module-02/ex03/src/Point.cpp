/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:53:46 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/10 14:44:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

Point::Point(void) : x(0), y(0) {}
Point::~Point(void) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point &Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Point temp = other;
		*this = temp;
	}
	return (*this);
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed const	Point::getX(void) const
{
	return (x);
}

Fixed const	Point::getY(void) const
{
	return (y);
}

bool Point::operator==(const Point& other) const
{
	return ((this->getX() == other.getX()) && (this->getY() == other.getY()));
}