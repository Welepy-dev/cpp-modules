/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:35 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 20:40:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <cfloat>
# include <iomanip>
# include <ios>

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

void	convertToInt(const std::string& str);
void	convertToChar(const std::string& str);
void	convertToFloat(const std::string& str);
void	convertToDouble(const std::string& str);

#endif
