/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:40:57 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 18:25:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <vector>

int	main()
{
	Span sp = Span(5);

	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);

	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);


	/*Span sp2 = Span(5);
	sp2.addNumber(v.begin(), v.end());*/

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}
