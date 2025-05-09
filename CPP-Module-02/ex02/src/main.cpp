/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:25:09 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/08 18:46:56 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout	<<	a	<< std::endl;
	std::cout	<<	++a	<< std::endl;
	std::cout	<<	a	<< std::endl;
	std::cout	<<	a++	<< std::endl;
	std::cout	<<	a	<< std::endl;
	
	std::cout	<<	b	<< std::endl;

	std::cout	<<	Fixed::min( a, b )	<< std::endl;

	return (0);
}
