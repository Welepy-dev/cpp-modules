/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:40:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/12/15 16:46:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::~PmergeMe( ) { }

PmergeMe::PmergeMe(char **av) {
	std::vector<std::string> temp;
	for (int i = 1; av[i]; i++) {
		temp = this->split(std::string(av[i]));
		this->chopped_string.insert(this->chopped_string.end(), temp.begin(), temp.end());
	}
	std::vector<std::string>::size_type size = this->chopped_string.size();
	for (size_t i = 0; i < size; i++) {
		if (this->chopped_string[i].find_first_not_of("0123456789") != std::string::npos)
			std::cerr << "Error, bad argument: " << this->chopped_string[i] << std::endl;
		this->numbers.push_back(std::atoi(this->chopped_string[i].c_str()));
	}
	
}

void PmergeMe::sort(void) {
	std::cout << "Before: ";
	std::vector<int>::size_type size = this->numbers.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << this->numbers[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < size; i++) {
		std::cout << this->numbers[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<std::string> PmergeMe::split(const std::string& input) {
    std::vector<std::string> result;
    std::string token;
    std::string::size_type i = 0;
    const std::string::size_type n = input.size();

    // Skip leading spaces and tabs
    while (i < n && (input[i] == ' ' || input[i] == '\t'))
        ++i;

    while (i < n) {
        // Collect characters for the current token
        token.clear();
        while (i < n && input[i] != ' ' && input[i] != '\t') {
            token += input[i];
            ++i;
        }

        if (!token.empty())
            result.push_back(token);

        // Skip consecutive spaces and tabs
        while (i < n && (input[i] == ' ' || input[i] == '\t'))
            ++i;
    }

    return result;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->chopped_string = other.chopped_string;
		this->numbers = other.numbers;
	}
	return (*this);
}

PmergeMe::PmergeMe(const PmergeMe &other) { 
	*this = other;
}

