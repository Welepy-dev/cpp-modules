/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToFloat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:25:58 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 20:39:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	convertToFloat(const std::string &str)
{
	char	*end;

	std::cout << "float: ";

	errno = 0;
    float value = std::strtof(str.c_str(), &end);

	if (str.length() == 1 && !std::isdigit(str[0]))
		value = str[0];
	else
		value = std::atoi(str.c_str());
	bool hasDigit = str.find_first_of("0123456789") != std::string::npos;
	bool hasAlpha = str.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
	if (str.length() > 1 && hasAlpha && hasDigit)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else
	{
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
		if (errno == ERANGE || value > FLT_MAX || value < -FLT_MAX)
			std::cout << "Out of range for float\n";
    }
}
