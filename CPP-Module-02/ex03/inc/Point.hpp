/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:50:04 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/09 13:53:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point
{
	private:
		
		Fixed const x;
		Fixed const y;

	public:
		
		Point(void);
		Point(const float x, const float y);
		~Point(void);
		Point(const Point &other);					//copy constructor
		Point &operator=(const Point &other);		//copy assignment constructor
		
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
		// void		setX(Fixed X) const;
		// void		setY(Fixed Y) const;
};

#endif