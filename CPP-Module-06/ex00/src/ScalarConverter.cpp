/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/30 20:43:02 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <climits>
#include <cstdlib>

bool isSymbol(char c) { return (c == '-' || c == '+' || c == '.' || c == 'f'); }

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
}

/*
 * nan nanf inf inff -inf -inff +inf +inff
 *
char: impossible
int: impossible
float: nanf
double: nan
*/
