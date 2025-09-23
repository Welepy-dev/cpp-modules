/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToDouble.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:38:59 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 20:41:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	convertToDouble(const std::string &str)
{
	char	*end;

	std::cout << "double: ";

	errno = 0;
    double value = std::strtof(str.c_str(), &end);

	if (str.length() == 1 && !std::isdigit(str[0]))
		value = str[0];
	else
		value = std::atof(str.c_str());
	bool hasDigit = str.find_first_of("0123456789") != std::string::npos;
	bool hasAlpha = str.find_first_of("abcdeghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
	if (str.length() > 1 && hasAlpha && hasDigit)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else
	{
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
		if (errno == ERANGE || value > FLT_MAX || value < -FLT_MAX)
			std::cout << "Out of range for double\n";
    }
}
