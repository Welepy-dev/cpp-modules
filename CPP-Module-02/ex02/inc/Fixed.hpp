/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:58:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/08 18:36:17 by marcsilv         ###   ########.fr       */
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

		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		float				toInt(void) const;
	
		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;
	
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;
		//we do not return references because we want to create new independent values, not modifying existing ones
		
		Fixed				&operator++(void);
		Fixed				&operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);

		static Fixed		&min(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
		static Fixed		&max(Fixed& a, Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);
};

std::ostream&			operator<<(std::ostream &out, const Fixed &fixed);

#endif