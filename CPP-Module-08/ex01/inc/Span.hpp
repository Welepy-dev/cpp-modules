/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:12:36 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 17:30:44 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>
# include <stdexcept>
# include <algorithm>

class Span {

	public:
		Span(): _size(0), _number_of_elements(0) { /*std::cout << "Span's default constructor called" << std::endl;*/ } ;
		Span(unsigned int N): _size(N), _number_of_elements(0) { /*std::cout << "Span's parametized constructor operator called" << std::endl;*/ } ;
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span() { };

		void	addNumber(int n);
		int		longestSpan(void);
		int		shortestSpan(void);
	
	private:
		unsigned int		_size;
		std::vector<int>	_data;
		unsigned int		_number_of_elements;
		
};

#endif
