#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
	
	static void	convert(const std::string &literal);
	
	private:
		ScalarConverter();
		/*ScalarConverter(const ScalarConverter &other);*/

};

void	convertToChar(const std::string& str);
void	convertToInt(const std::string& str);
void	convertToFloat(const std::string& str);
//void	convertToDouble(const std::string& str);

#endif
