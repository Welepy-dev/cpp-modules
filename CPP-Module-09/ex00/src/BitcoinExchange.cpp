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
		this->_csv_path = other._csv_path;
		this->_txt_path = other._txt_path;
		this->_csv.close();
		this->_csv.clear();
		this->_csv.open(other._csv_path.c_str());
		this->_year = other._year;
		this->_month = other._month;
		this->_day = other._day;
		this->_value = other._value;
		this->_line_number = other._line_number;
	}
	return (*this);
}

std::vector<std::string> BitcoinExchange::split(const std::string& s, const std::string& delimiter) {
    std::vector<std::string>	tokens;
    std::string::size_type		start = 0;
    std::string::size_type		end;

    while ((end = s.find(delimiter, start)) != std::string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + delimiter.size();
    }

    tokens.push_back(s.substr(start));
    return (tokens);
}

void BitcoinExchange::getFiles(const char *csv, const char *txt) {
	this->_csv.open(csv);
	this->_txt.open(txt);
	if (this->_csv.good() == false)
		throw std::runtime_error("File not found: " + std::string(csv) + ".");
	if (this->_txt.good() == false)
		throw std::runtime_error("File not found: " + std::string(txt) + ".");

	this->_csv_path = csv;
	this->_txt_path = txt;
	size_t pos = this->_csv_path.rfind(".csv");
	if (pos == std::string::npos || pos != this->_csv_path.length() - 4)
		throw std::runtime_error("Wrong file extension, use a csv.");

	std::string	csv_line;
	std::string	txt_line;
	std::getline(this->_csv, csv_line);
	std::vector<std::string> csv_header = this->split(csv_line, ",");

	if (csv_header[0].compare("date") != 0 || csv_header[1].compare("exchange_rate") != 0)
		std::cerr << "Error: bad input => " + csv_line << std::endl;

	std::getline(this->_txt, txt_line);
	std::vector<std::string> txt_header = this->split(txt_line, " | ");

	if (txt_header[0].compare("date") != 0 || txt_header[1].compare("value") != 0)
		std::cerr << "Error: bad input => " + txt_line << std::endl;

	while (std::getline(this->_txt, txt_line)) {
		this->convert(csv_line, txt_line);
	}
}

BitcoinExchange::BitcoinExchange(const char *csv, const char *txt) {
	getFiles(csv, txt);
}

bool BitcoinExchange::is_valid_date(int year, int month, int day) {
	if ((this->_year < 2009) || (this->_year == 2009 && this->_day < 3 && this->_month < 1)) 
		return (false);
	if (month < 1 || month > 12)
		return (false);
	

	int maxDay = this->days_in_month(month, year);
	if (day < 1 || day > maxDay)
		return (false);
	
	return (true);
}

bool BitcoinExchange::validate_line(std::string line, std::string delimiter) {

	std::vector<std::string> date = this->split(line, delimiter);
	std::string file_type;
	/*std::string yearStr, monthStr, dayStr, valueStr;
	std::stringstream ss(line);
	std::getline(ss, yearStr, '-');
	std::getline(ss, monthStr, '-');
	std::getline(ss, dayStr, ',');
	std::getline(ss, valueStr);

	std::stringstream(yearStr) >> this->_year;
	std::stringstream(monthStr) >> this->_month;
	std::stringstream(dayStr) >> this->_day;
	std::stringstream(valueStr) >> this->_value;*/
	if (delimiter.find("|"))
		file_type = "txt";
	else
		file_type = "csv";

	if (this->is_valid_date(this->_year, this->_month, this->_day) == false)
		std::cerr << "Error in " << file_type << " : bad input => " << date[0] << std::endl;
	return (true);
}

void BitcoinExchange::convert(std::string csv_line, std::string txt_line) {
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
