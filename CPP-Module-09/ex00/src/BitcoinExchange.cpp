/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:04:45 by marcsilv          #+#    #+#             */
/*   Updated: 2025/11/29 18:43:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( ) { }
BitcoinExchange::~BitcoinExchange( ) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_filepath = other._filepath;
		this->_file.close();
		this->_file.clear();
		this->_file.open(other._filepath.c_str());
		this->_year = other._year;
		this->_month = other._month;
		this->_day = other._day;
		this->_value = other._value;
		this->_line_number = other._line_number;
	}
	return (*this);
}

void BitcoinExchange::getFile(const char *csv, const char *txt) {
	this->_csv.open(csv);
	this->_txt.open(txt);
	if (this->_csv.good() == 0)
		throw std::runtime_error("File not found: " + std::string(csv) + ".");
	if (this->_txt.good() == 0)
		throw std::runtime_error("File not found: " + std::string(txt) + ".");

	this->_csv_path = csv;
	size_t pos = this->_csv_path.rfind(".csv");
	if (pos == std::string::npos || pos != this->_csv_path.length() - 4)
		throw std::runtime_error("Wrong file extension, use a csv.");

	std::string line;
	int	line_number = 1;
	std::getline(_csv, line);
	std::stringstream ss;
	while (std::getline(_csv, line)) {
		line_number++;
		ss << line_number;
		this->convert(line, ss.str());
		ss.str("");
		ss.clear();
	}
}

BitcoinExchange::BitcoinExchange(const char *csv, const char *txt) {
	getFile(csv, txt);
}

bool BitcoinExchange::is_valid_date(int year, int month, int day) {
	if (month < 1 || month > 12) return (false);
	

	int maxDay = this->days_in_month(month, year);
	if (day < 1 || day > maxDay) return (false);
	
	return (true);
}

void BitcoinExchange::convert(std::string csv_line, std::string txt_line, std::string line_number) {
	std::stringstream ss(line);
	std::string yearStr, monthStr, dayStr, valueStr;
	std::getline(ss, yearStr, '-');
	std::getline(ss, monthStr, '-');
	std::getline(ss, dayStr, ',');
	std::getline(ss, valueStr);

	std::stringstream(yearStr) >> this->_year;
	std::stringstream(monthStr) >> this->_month;
	std::stringstream(dayStr) >> this->_day;
	std::stringstream(valueStr) >> this->_value;
	if ((this->_year < 2009) || (this->_year == 2009 && this->_day < 3 && this->_month < 1)) 
		throw std::runtime_error("Error at line: " + line_number + " Bitcoin did not exist in this date!");
	if (this->is_valid_date(this->_year, this->_month, this->_day) == false)
		throw std::runtime_error("Error at line: " + line_number + " Invalid date.");
}

int BitcoinExchange::days_in_month(int month, int year) {
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
