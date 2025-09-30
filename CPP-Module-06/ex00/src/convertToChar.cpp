/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToChar.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>        +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:27:26 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:03 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	convertToChar(const std::string& str)
{
	std::cout << "char: ";
	char c = 0;
	bool hasDigit = str.find_first_of("0123456789") != std::string::npos;
	bool hasAlpha = str.find_first_of("abcdeghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
	if ((str.length() > 1 && hasAlpha && hasDigit) || (str.compare("nan")) )
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (str.length() == 1 && !std::isdigit(str[0]))
		c = str[0];
	else
		c = static_cast<char>(std::atoi(str.c_str()));
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (static_cast<unsigned char>(c) > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}
/*
bool hasDigit = str.find_first_of("0123456789") != std::string::npos;
bool hasAlpha = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;

if (str.length() > 1 && hasDigit && hasAlpha)
{
    // mixed letters+digits, e.g. "2a" or "a2" — invalid as a numeric literal
}*/
