/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:08:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/08 11:01:04 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		
	public:
		Fixed();
		~Fixed();
		Fixed &operator=(const Fixed &other);
		bool operator==(cont Fixed &other);
};

Fixed::Fixed() {}
Fixed::~Fixed() {}

#endif