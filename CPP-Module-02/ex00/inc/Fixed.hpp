/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:08:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/08 17:12:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	bits = 8;

	public:
		Fixed();									//default constructor
		~Fixed();									//destructor
		Fixed(const Fixed &other);					//copy constructor
		Fixed &operator=(const Fixed &other);		//copy assignment constructor
		
		int		getRawBits(void) const;						
		void	setRawBits(int const raw);
};

#endif