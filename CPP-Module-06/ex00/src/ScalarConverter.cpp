/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/03 15:18:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <climits>
#include <string>

template <typename T>
Container cast(T a)
{
	Container container;
	container.intValue = static_cast<int>(a);
	container.charValue = static_cast<char>(a);
	container.floatValue = static_cast<float>(a);
	container.doubleValue = static_cast<double>(a);
	return (container);
}

Container	identify(const std::string &literal)
{
	Container	container;
		if (literal.length() == 1)
			container = cast(literal[0]); //char int
		else if (std::strspn(literal.c_str(), NUMBERS_AND_SYMBOLS) == literal.length()) //float
			container = cast(std::atof(literal.c_str()));
		else if (std::strspn(literal.c_str(), "0123456789+-.") == literal.length()) //double
			container = cast(static_cast<double>(std::atof(literal.c_str())));
		else if (std::strspn(literal.c_str(), "0123456789+-") == literal.length()) //int
			container = cast(std::atoi(literal.c_str()));
	return (container);
}

void	printConversion(double d)
{
	std::cout << "Double: " << std::fixed << std::setprecision(1) << std::showpoint << d << std::endl; // fix setprecision
}

void	printConversion(float f)
{
	std::cout << "Float: " << std::fixed << std::setprecision(1) << std::showpoint << f << "f" << std::endl;
}
void	printConversion(int i)
{
	std::cout << "Int: "  << i << std::endl;
}

void	printConversion(char c)
{
	if (c < 0 || std::isspace(c) || !std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "Char: "  << c << std::endl;
	// impossible
}

bool has_multiple_occurrences(const std::string &s, char c) { return std::count(s.begin(), s.end(), c) > 1; }

bool	isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff"
          || literal == "-inf" || literal == "-inff" || literal == "+inf" || literal == "+inff");
}

void	impossible(void)
{
	std::cout << "int: impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool	validate(const std::string literal)
{
	if (isPseudoLiteral(literal) == false)
	{
		if (literal.length() == 0 || std::atol(literal.c_str()) > INT_MAX || std::atol(literal.c_str()) < INT_MIN)
		  return (false);
		if (literal.length() > 1 && std::strcspn(literal.c_str(), NUMBERS_AND_SYMBOLS) == literal.length())
		  return (false);
		if (has_multiple_occurrences(literal, '.') || has_multiple_occurrences(literal, '+') 
		  || has_multiple_occurrences(literal, '-') || has_multiple_occurrences(literal, 'f'))
		  return (false);
		//size_t fPos = literal.find('f');
		//if (fPos != std::string::npos && fPos != literal.length() - 1)
		//  return false;
		/*size_t plusPos = literal.find('+');
		if (plusPos != std::string::npos && plusPos != literal.length() - 1)
		  return false;
		size_t minusPos = literal.find('-');
		if (minusPos != std::string::npos && minusPos != literal.length() - 1)
		  return false;*/
		if (literal.find("+") != 0)
		  return (false);
		bool hasDigit = literal.find_first_of(NUMBERS) != std::string::npos;
		bool hasAlpha = literal.find_first_of(ALPHABETS) != std::string::npos;
		if (hasAlpha && hasDigit)
		  return (false);
	}
	return (true);
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (validate(literal) == false)
	{
		impossible();
		return ;
	}

	if (isPseudoLiteral(literal)) {
	        // Handle char
	        std::cout << "char: impossible" << std::endl;
	        // Handle int
	        std::cout << "int: impossible" << std::endl;
	
	        // Handle float / double depending on suffix
	        if (literal == "nan" || literal == "+inf" || literal == "-inf")
	        {
	            // double literal, so float version just adds "f"
	            std::cout << "float: " << literal << "f" << std::endl;
	            std::cout << "double: " << literal << std::endl;
	        }
	        else // nanf, +inff, -inff
	        {
	            // float literal, so double version just removes trailing "f"
	            std::cout << "float: " << literal << std::endl;
	            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
	        }
	        return;
	    }
		Container container = identify(literal);
		printConversion(container.charValue);
		printConversion(container.intValue);
		printConversion(container.floatValue);
		printConversion(container.doubleValue);
}

/*
 * nan nanf inf inff -inf -inff +inf +inff
*/
