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
	}
	return (*this);
}

void BitcoinExchange::getFile(const char *filepath) {
	this->_file.open(filepath);
	if (this->_file.good() == 0)
		throw std::runtime_error("File not found: " + std::string(filepath) + ".");

	this->_filepath = filepath;
	size_t pos = this->_filepath.rfind(".csv");
	if (pos == std::string::npos || pos != this->_filepath.length() - 4)
		throw std::runtime_error("Wrong file extension, use a csv.");

	std::string line;
	int	line_number = 1;
	std::getline(_file, line);
	std::stringstream ss;
	while (std::getline(_file, line)) {
		line_number++;
		ss << line_number;
		Line curline(line, ss.str());
		ss.str("");
		ss.clear();
	}

}

BitcoinExchange::BitcoinExchange(char *filepath) {
	getFile(filepath);
}

