/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:08 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/10 18:24:44 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

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
		this->_txt.close();
		this->_txt.clear();
		this->_txt.open(other._txt_path.c_str());
	}
	return (*this);
}

void BitcoinExchange::check_and_assign_files(const char *csv, const char *txt) {
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

}

static std::string trim(const std::string& str) {
	size_t start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ""; // only whitespace
	size_t end = str.find_last_not_of(" \t");
	return str.substr(start, end - start + 1);
}

std::vector<std::string> BitcoinExchange::split(const std::string& s, const std::string& delimiter) {
	std::vector<std::string> tokens;
	std::string::size_type start = 0;
	std::string::size_type end;

	while ((end = s.find(delimiter, start)) != std::string::npos) {
		std::string token = s.substr(start, end - start);
		tokens.push_back(trim(token));
		start = end + delimiter.size();
	}
	// Last token
	tokens.push_back(trim(s.substr(start)));

	return (tokens);
}

bool BitcoinExchange::get_csv_pair(const std::string &line, std::pair<time_t, double> *pair) {
	std::vector<std::string> split_line = this->split(line, ",");
	if (split_line.size() < 2)  {
		std::cerr << "Error: " << line << std::endl;
		return (false);
	}

	double exchange_rate = std::atof(split_line[1].c_str());
	time_t date;

	struct tm t;
	memset(&t, 0, sizeof(t));

	const char *ret = strptime(split_line[0].c_str(), "%Y-%m-%d", &t);
	if (!ret || *ret != '\0') {
		std::cerr << "Error: " << line << std::endl;
		return (false);
	}

	t.tm_isdst = -1;
	date = mktime(&t);
	*pair = std::make_pair(date, exchange_rate);
	return (true);
}

void BitcoinExchange::print_value(const std::string &line) {
	std::vector<std::string> split_line = this->split(line, "|");
	if (split_line.size() < 2)  {
		std::cerr << "Error: " << line << std::endl;
		return ;
	}
	double exchange_rate = std::atof(split_line[1].c_str());
	if (exchange_rate > 1000.0f) {
		std::cerr << "value too high" << std::endl;
	}
	time_t date;

	struct tm t;
	memset(&t, 0, sizeof(t));

	const char *ret = strptime(split_line[0].c_str(), "%Y-%m-%d", &t);
	if (!ret || *ret != '\0') {
		std::cerr << "Error: " << line << std::endl;
		return ;
	}

	t.tm_isdst = -1;
	date = mktime(&t);
	std::cout << this->_csv_dict[date] * exchange_rate << std::endl;
}

void BitcoinExchange::fill_csv_dict(void) {
	if (!this->_csv.is_open()) {
		throw std::runtime_error("CSV file not open.");
	}

	// Read header
	std::string					line;
	std::pair<time_t, double>	pair;
	
	std::getline(this->_csv, line);

	std::vector <std::string> csv_header = this->split(line, ",");
	if (csv_header[0].compare("date") != 0 || csv_header[1].compare("exchange_rate") != 0)
		std::cerr << "Error: bad input => " + line << std::endl;

	while(std::getline(this->_csv, line)) {
		if (this->get_csv_pair(line, &pair) == false)
			continue ;
		this->_csv_dict.insert(pair);
	}
}

void BitcoinExchange::conversion(void) {
	if (!this->_txt.is_open()) {
		throw std::runtime_error("input file not open.");
	}

	// Read header
	std::string					line;
	
	std::getline(this->_txt, line);

	std::vector <std::string> csv_header = this->split(line, "|");
	if (csv_header[0].compare("date") != 0 || csv_header[1].compare("value") != 0)
		std::cerr << "Error: bad input => " + line << std::endl;

	while(std::getline(this->_txt, line)) {
		this->print_value(line);
	}
	
}

void BitcoinExchange::get_files(const char *csv, const char *txt) {
	this->check_and_assign_files(csv, txt);
	this->fill_csv_dict();
	this->conversion();
}

BitcoinExchange::BitcoinExchange(const char *csv, const char *txt) {
	get_files(csv, txt);
}

