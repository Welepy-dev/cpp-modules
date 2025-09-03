/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToInt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:21 by codespace         #+#    #+#             */
/*   Updated: 2025/08/02 11:20:31 by codespace        ###   ########.fr       */
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
	if (str == "nan" || str == "inf" || str == "-inf" || str == "nanf" || str == "inff" || str == "-inff")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << c << std::endl;
}