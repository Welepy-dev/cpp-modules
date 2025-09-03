#include "../inc/ScalarConverter.hpp"

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
}*/

ScalarConverter::~ScalarConverter()
{ 
	std::cout << "ScalarConverter's default destructor called" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	convertToChar(literal);
	convertToInt(literal);
	convertToFloat(literal);
	//convertToDouble(literal);
}