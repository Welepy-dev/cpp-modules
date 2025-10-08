/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:42:35 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/03 14:10:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define NUMBERS "0123456789"
# define ALPHABETS "abcdeghijklmnopqrstuvwxyzABCDEGHIJKLMNOPQRSTUVWXYZ"
# define SYMBOLS "-+f."
# define NUMBERS_AND_SYMBOLS "0123456789-+f."

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
		static void	convert(const std::string &literal);

	private:
		ScalarConverter();

};

typedef struct s_container
{
	char	type; 
	char	charValue;
	float	floatValue;
	double	doubleValue;
	int		intValue;
} Container;

#endif
