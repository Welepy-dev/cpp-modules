/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:32:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 18:16:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(const Span &other)
{
	/*std::cout << "Span's copy constructor operator called" << std::endl;*/
	*this = other;
}

Span &Span::operator=(const Span &other) {
	/*std::cout << "Span's Copy assignment operator called" << std::endl;*/
	if (this != &other) {
		this->_size = other._size;
		this->_data = other._data;
		this->_number_of_elements = other._number_of_elements;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (_number_of_elements < _size) {
		_data.push_back(n);
		_number_of_elements++;
		if (_data.size() > 1)
			std::sort(_data.begin(), _data.end());
	}
	else
		throw std::length_error("Exceeded number of elements!");
}

int	Span::shortestSpan(void) {
	if (_data.size() == 1)
		throw std::length_error("Can't have span with 1 number!");

	int	temp = _data[1] - _data[0];
	int	span = temp;

	for (unsigned int i = 1; i < _number_of_elements; ++i)
	{
		temp = _data[i] - _data[i - 1];
		if (temp < span)
			span = temp;
	}
	return (span);
}

int	Span::longestSpan(void) {
	if (_data.size() == 1)
		throw std::length_error("Can't have span with 1 number!");
	return (_data.back() - _data.front());
}
