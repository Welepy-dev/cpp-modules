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

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <sstream>
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
		std::ifstream	_file;
		std::string		_filepath;

		class Line {
			public:
				Line() { };
				~Line() { };
				Line(const Line &other) { *this = other; };
				Line(std::string line, std::string line_number) {
					std::stringstream ss(line);
					std::string yearStr, monthStr, dayStr, valueStr;

					std::getline(ss, yearStr, '-');
					std::getline(ss, monthStr, '-');
					std::getline(ss, dayStr, ',');
					std::getline(ss, valueStr);

					std::stringstream(yearStr) >> this->year;
					std::stringstream(monthStr) >> this->month;
					std::stringstream(dayStr) >> this->day;
					std::stringstream(valueStr) >> this->value;
					if ((this->year < 2009) || (this->year == 2009 && this->day < 3 && this->month < 1)) 
						throw std::runtime_error("Error at line: " + line_number + " Bitcoin did not exist in this date!");
					if (this->is_valid_date(this->year, this->month, this->day) == false)
						throw std::runtime_error("Error at line: " + line_number + " Invalid date.");
				};
				Line	 &operator=(const Line &other) {
					if (this != &other) {
						this->day = other.day;
						this->month = other.month;
						this->year = other.year;
						this->value = other.value;
					}
					return (*this);
				};
				int		days_in_month(int month, int year) {
					switch (month) {
						case 1: case 3: case 5: case 7: case 8: case 10: case 12:
							return (31);
						case 4: case 6: case 9: case 11:
							return (30);
						case 2:
							if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
								return (29);
							else
								return (29);
					}
					return (0);
				}
				bool	is_valid_date(int year, int month, int day) {
					if (month < 1 || month > 12) return (false);
					
					int maxDay = this->days_in_month(month, year);
					if (day < 1 || day > maxDay) return (false);
					
					return (true);
				}
			private:
				int	year;
				short			month;
				short			day;
				float			value;
				int				line_number;
		};
		Line	line;
};
