/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToInt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:12 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	convertToInt(const std::string& str)
{
	std::cout << "int: ";
	int c = 0;
	if (str.length() == 1 && !std::isdigit(str[0]))
		c = str[0];
	else
		c = std::atoi(str.c_str());
	bool hasDigit = str.find_first_of("0123456789") != std::string::npos;
	bool hasAlpha = str.find_first_of("abcdeghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
	if (str.length() > 1 && hasAlpha && hasDigit)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << c << std::endl;
}
