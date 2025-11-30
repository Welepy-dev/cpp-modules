/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:58:05 by marcsilv          #+#    #+#             */
/*   Updated: 2025/11/29 18:43:24 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <fstream>

class BitcoinExchange {

	public:
		BitcoinExchange();
		BitcoinExchange(char *filepath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		
	private:
		void			getFile(const char *filepath);
		class Line {
			public:
				Line() { };
				Line(const Line &other) { *this = other; };
				Line &operator=(const Line &other);
				~Line();
			private:
				long long int	year;
				short			month;
				short			day;
				short			value;
				
		};

		std::ifstream	_file;
		std::string		_filepath;
	
};
