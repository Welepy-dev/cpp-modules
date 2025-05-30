/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:58:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/09 17:21:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixed_point;
		static const int	bits = 8;

	public:
		Fixed();									//default constructor
		~Fixed();									//destructor
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &other);					//copy constructor
		Fixed &operator=(const Fixed &other);		//copy assignment constructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);


#endif