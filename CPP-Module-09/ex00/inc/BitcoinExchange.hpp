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
#include <vector>

class BitcoinExchange {

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange(const char *csv, const char *txt);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		
	private:
		short							_day;
		std::ifstream					_csv;
		std::ifstream					_txt;
		int								_year;
		std::map<std::string, double>	_dict;
		float							_value;
		short							_month;
		std::string						_csv_path;
		std::string						_txt_path;
		std::vector<std::string>		_csv_vector;
		std::vector<std::string>		_txt_vector;
		int								_line_number;

		int								days_in_month(int month, int year);
		void							getFiles(const char *csv, const char *txt);
		bool							is_valid_date(int year, int month, int day);
		void							convert(std::string csv_line, std::string txt_line);
		bool							check_line(std::string line, std::string line_number);
		std::vector<std::string>		split(const std::string &s, const std::string &delimiter);
		bool							validate_line(std::string csv_line, std::string txt_line);
};
