/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 20:41:03 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter's default constructor called" << std::endl;
} 
 
/*ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{ 
	std::cout << "ScalarConverter's copy assignment operator called" << std::endl;

	return (*this);
}*/
 
/*ScalarConverter::ScalarConverter(const ScalarConverter &other)
{ 
	std::cout << "ScalarConverter's copy constructor called" << std::endl;
 
	*this = other;
	(void)other;


	else if (literal.find_first_of(".f") != std::string::npos)
		return ('f');
	else if (literal.find_first_of(".f") != std::string::npos)
		return ('f');
	else if (literal.find_first_of(".f") != std::string::npos)
		return ('f');

}*/

ScalarConverter::~ScalarConverter()
{ 
	std::cout << "ScalarConverter's default destructor called" << std::endl;
}
bool is_all_digits(const std::string &s)
{
    if (s.empty()) return (false);
    for (std::string::size_type i = 0; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

bool has_multiple_occurrences(const std::string &s, char c) { return std::count(s.begin(), s.end(), c) > 1; }

char	identify(const std::string &literal)
{
	if (literal.length() == 1)
		return ('c');
	else if (literal.length() == 0)
		return (0);
	else if (is_all_digits(literal) && !has_multiple_occurrences(literal, '+') && !has_multiple_occurrences(literal, '-') && !(literal.find('+') != std::string::npos && literal.find('-') != std::string::npos))
		return ('i');
	else if (literal.)
	return (0);
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (!identify(literal))
	{
		std::cout << "IMPOSSIVEL" << std::endl; exit(1);
	}
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}
