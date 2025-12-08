/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:39:02 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/07 11:39:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <cstdint>
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <string>
# include <exception>
# include <stdexcept>
# include <fstream>
# include <vector>
# include <map>
# include <limits>

class BitcoinExchange {

	public:
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange(const char *csv, const char *txt);
		BitcoinExchange &operator=(const BitcoinExchange &other);

	private:
		std::ifstream				_csv;
		std::ifstream				_txt;
		std::string					_csv_path;
		std::string					_txt_path;
		std::map<time_t, double>	_csv_dict;

		std::ifstream				fill_csv_dict(void);
		void						get_files(const char *csv, const char *txt);
		void						check_and_assign_files(const char *csv, const char *txt);
		std::vector<std::string>	split(const std::string& s, const std::string& delimiter);
		std::map<time_t, double>	append_to_dict(const std::string &line, const std::string &delimiter);
		void						validate_line(const std::string &line);
};

#endif
