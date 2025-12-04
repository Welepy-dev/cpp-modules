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
#include <map>
#include <limits>

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
		std::map<std::string, double>	_csv_dict;
		std::map<std::string, double>	_txt_dict;
		int								_line_number;

		int								days_in_month(int month, int year);
		void							getFiles(const char *csv, const char *txt);
		bool							is_valid_date(int year, int month, int day);
		bool							check_line(std::string line, std::string line_number);
		std::vector<std::string>		split(const std::string &s, const std::string &delimiter);
		void							convert(const std::string &csv_line, const std::string &txt_line);
		bool							validate_line(const std::string &line, const std::string &delimiter);
		std::map<std::string, double>	append_to_dict(const std::string &line, const std::string &delimiter);
};
