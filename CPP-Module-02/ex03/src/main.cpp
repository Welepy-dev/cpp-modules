/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:25:09 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/09 14:30:15 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

float triangleArea(Point const a, Point const b, Point const c)
{
	float ax = a.getX().toFloat();
	float ay = a.getY().toFloat();
	float bx = b.getX().toFloat();
	float by = b.getY().toFloat();
	float cx = c.getX().toFloat();
	float cy = c.getY().toFloat();

	return 0.5f * std::abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float totalArea = triangleArea(a, b, c);
	float area1 = triangleArea(point, b, c);
	float area2 = triangleArea(a, point, c);
	float area3 = triangleArea(a, b, point);

	float sum = area1 + area2 + area3;
	return (std::abs(totalArea - sum) < 0.001f);
}

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	Point inside(2.5f, 2.0f);
	Point outside(5.0f, 5.0f);
	Point edge(2.5f, 0.0f);

	std::cout << "Point inside triangle: " 
			  << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;

	std::cout << "Point outside triangle: " 
			  << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;

	std::cout << "Point on edge of triangle: " 
			  << (bsp(a, b, c, edge) ? "YES" : "NO") << std::endl;

	return 0;
}

