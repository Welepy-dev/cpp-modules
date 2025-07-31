/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertToChar.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:27:26 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 16:27:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void	convertToChar(const std::string& str)
{
	std::cout << "char: ";
	if (str.length() == 1)
	{
		int c = str[0];
		if (std::isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}