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
#include <cstdlib>

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
		this->_txt_dict = this->append_to_dict(txt_line, "|");
	}
	while (std::getline(this->_csv, csv_line)) {
		this->_csv_dict = this->append_to_dict(csv_line, ",");
	}
}

void BitcoinExchange::convert(const std::string &csv_line, const std::string &txt_line) {
    // Split lines
    std::vector<std::string> txt_date = this->split(txt_line, "|");
    std::vector<std::string> csv_date = this->split(csv_line, ",");

    // Validate split results
    if (txt_date.size() < 2 || csv_date.size() < 2) {
        std::cerr << "Error: malformed input line\n";
        return;
    }

    // Trim whitespace (recommended to implement trim())
    std::string txt_key = trim(txt_date[0]);
    std::string csv_key = trim(csv_date[0]);

    // Convert values
    double txt_value = std::atof(txt_date[1].c_str());
    double csv_value = std::atof(csv_date[1].c_str());

    // Check for matching dates
    if (txt_key == csv_key) {
        double result = txt_value * csv_value;
        _dict[txt_key] = result;

        std::cout << csv_line << " " << txt_line << " -> " << result << std::endl;
    } 
    else {
        // Store zero only for the txt date (optional, based on your design)
        _dict[txt_key] = 0.0;

        std::cerr << "Warning: dates do not match: "
                  << txt_key << " vs " << csv_key << std::endl;
    }
}

std::map<std::string, double> BitcoinExchange::append_to_dict (
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

/*bool BitcoinExchange::validate_line(const std::string &line, const std::string &delimiter) {
	
	std::vector<std::string> date = this->split(line, delimiter);
	std::string file_type;
	
	if (delimiter.find("|"))
		file_type = "txt";
	else
		file_type = "csv";

	if (this->is_valid_date(this->_year, this->_month, this->_day) == false) {
		std::cerr << "Error in " << file_type << " : bad input => " << date[0] << std::endl;
		return (false);
	}
	return (true);
}*/


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
				return (28);
	}
	return (0);
}
