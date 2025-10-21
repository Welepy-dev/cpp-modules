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

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	unsigned int limit = 0;
	for (std::vector<int>::iterator it = first; it != last; ++it) {
		addNumber(*it);
		limit++;
		if (limit > _size)
			throw std::length_error("Exceeded number of elements!");
	}
}

long	Span::shortestSpan(void) {
	if (_data.size() == 1)
		throw std::length_error("Can't have span with 1 number!");

	long	temp = static_cast<long>(_data[1]) - _data[0];
	long	span = temp;

	for (unsigned int i = 1; i < _number_of_elements; ++i)
	{
		temp = static_cast<long>(_data[i]) - _data[i - 1];
		if (temp < span)
			span = temp;
	}
	return (span);
}

long	Span::longestSpan(void) {
	if (_data.size() == 1)
		throw std::length_error("Can't have span with 1 number!");
	long i1 = _data.back();
	long i2 = _data.front();
	return (i1 - i2);
}
