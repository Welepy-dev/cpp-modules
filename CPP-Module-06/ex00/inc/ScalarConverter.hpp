/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:35 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/02 15:25:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>
# include <cstdlib>
# include <cerrno>
# include <cfloat>
# include <iomanip>
# include <algorithm> // for std::count
# include <ios>

class ScalarConverter
{
	public:
		static void	convert(std::string &literal);

	private:
		ScalarConverter();

};

void	convertToInt(const std::string& str);
void	convertToChar(const std::string& str);
void	convertToFloat(const std::string& str);
void	convertToDouble(const std::string& str);

#endif
