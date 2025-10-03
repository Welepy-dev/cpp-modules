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

/*bool isSymbol(char c) { return (c == '-' || c == '+' || c == '.' || c == 'f'); }

ScalarConverter::ScalarConverter() { std::cout << "ScalarConverter's default constructor called" << std::endl; } 

ScalarConverter::~ScalarConverter() { std::cout << "ScalarConverter's default destructor called" << std::endl; }

bool is_all_digits(const std::string &s)
{
    if (s.empty()) return (false);
	for (std::string::size_type i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])) && isSymbol(s[i]))
			return false;
	if (s[s.length() - 1] == '-' || s[s.length() - 1] == '+' || s[s.length() - 1] == '.')
		return false;
    return true;
}

bool has_multiple_occurrences(const std::string &s, char c) { return std::count(s.begin(), s.end(), c) > 1; }

char	identify(const std::string &literal)
{
	if (literal.length() == 1)
		return ('c');
	else if (literal.length() == 0 || std::atol(literal.c_str()) > INT_MAX || std::atol(literal.c_str()) < INT_MIN)
		return (0);
	else if (is_all_digits(literal) && !has_multiple_occurrences(literal, '.') &&!has_multiple_occurrences(literal, '+') 
			&& !has_multiple_occurrences(literal, '-') && !(literal.find('+') != std::string::npos 
			&& literal.find('-') != std::string::npos))
		return ('i');
	else if (literal.compare("nan") || literal.compare("nanf") || literal.compare("inf") || literal.compare("inff") || literal.compare("-inf")
		|| literal.compare("-inff") || literal.compare("+inf") || literal.compare("+inff"))
			return ('a');
	return (0);
}

void	impossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit (1);
}

void	ScalarConverter::convert(const std::string &literal)
{
	int id = identify(literal);
	if (!id) impossible();
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	convertToDouble(literal);
}*/

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
// nan nanf inf inff -inf -inff +inf +inff

Container	identify(const std::string &literal)
{
	Container	container;
		if (literal.length() == 1)
			container = cast(literal[0]);
		else if (std::strspn(literal.c_str(), NUMBERS_AND_SYMBOLS) == literal.length())
			container = cast(std::atof(literal.c_str()));
		else if (std::strspn(literal.c_str(), "0123456789+-.") == literal.length())
			container = cast(static_cast<double>(std::atof(literal.c_str())));
		else if (std::strspn(literal.c_str(), "0123456789+-") == literal.length())
			container = cast(std::atoi(literal.c_str()));
	return (container);
}

void	printConversion(double d)
{
	std::cout << "Double: " << std::fixed << std::setprecision(1) << std::showpoint << d << std::endl;
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
	if (c < 0 || c > 127)
		std::cout << "Impossible" << std::endl;
	else if (std::isspace(c) || !std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "Char: "  << c << std::endl;
}

bool has_multiple_occurrences(const std::string &s, char c) { return std::count(s.begin(), s.end(), c) > 1; }

bool	isPseudoLiteral(const std::string &literal)
{
	return (!literal.compare("nan") || !literal.compare("nanf") || !literal.compare("inf") || !literal.compare("inff")
		|| !literal.compare("-inf") || !literal.compare("-inff") || !literal.compare("+inf") || !literal.compare("+inff"));
}

void	impossible(void)
{
	std::cout << "int: impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit (1);
}

bool	validate(const std::string literal)
{
	if (!isPseudoLiteral(literal))
	{
	if (literal.length() == 0 || std::atol(literal.c_str()) > INT_MAX || std::atol(literal.c_str()) < INT_MIN)
		return (false);
	if (literal.length() > 1 && std::strcspn(literal.c_str(), NUMBERS_AND_SYMBOLS) == literal.length())
		return (false);
	if (has_multiple_occurrences(literal, '.') || has_multiple_occurrences(literal, '+') 
		|| has_multiple_occurrences(literal, '-') || has_multiple_occurrences(literal, 'f'))
		return (false);
	if ((literal.find_first_of("f") == literal.length() - 1) || literal.find_first_of("+") > 0 || literal.find_first_of("-") > 0)
		return (false);
	if (literal.find_first_of(".") == 0 || literal.find_first_of(".") == literal.length() - 1)
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
		impossible();

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
