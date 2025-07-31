#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>

class ScalarConverter
{
	public:
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	
	static void	convert(const std::string &literal);
	
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);

};

void	convertToChar(const std::string& str);

#endif
