/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:08 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/08 14:30:51 by marcsilv         ###   ########.fr       */
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

std::map<time_t, double> BitcoinExchange::append_to_dict (
    const std::string& line,
    const std::string& delimiter)
{
    std::vector<std::string> a = this->split(line, delimiter);

    std::map<std::string, double> m;

    // Case 1: Not enough tokens → malformed input
    if (a.size() < 2) {
        m[line] = std::numeric_limits<double>::quiet_NaN(); 
        return m;
    }
    // Case 2: Value is invalid
    char* end;
    double value = std::strtod(a[1].c_str(), &end);

    if (*end != '\0') {  // not a fully valid number
        m[a[0]] = std::numeric_limits<double>::quiet_NaN();
        return m;
    }
    // Case 3: Valid entry
    m[a[0]] = value;
	std::cout << "date: " << a[0] <<  std::endl;
    return m;
}

std::ifstream BitcoinExchange::fill_csv_dict(void) {
	std::ifstream	file;
	std::string		line;
	
	std::getline(this->_csv, line);

	std::vector <std::string> csv_header = this->split(line, ",");
	if (csv_header[0].compare("date") != 0 || csv_header[1].compare("exchange_rate") != 0)
		std::cerr << "Error: bad input => " + line << std::endl;

	//put each line of the data to this->_csv_dict
	//also validate
	return (file);
}

void BitcoinExchange::get_files(const char *csv, const char *txt) {
	this->check_and_assign_files(csv, txt);
	this->_csv = this->fill_csv_dict();
}

BitcoinExchange::BitcoinExchange(const char *csv, const char *txt) {
	get_files(csv, txt);
}
