/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToChar.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:27:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 11:16:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <cctype>

void	convertToChar(const std::string& str)
{
	std::cout << "char: ";
	char c = 0;
	if (str.length() > 1 && !std::isdigit(str[0]))
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
