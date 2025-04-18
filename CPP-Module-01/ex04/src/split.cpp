/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:29:41 by welepy            #+#    #+#             */
/*   Updated: 2025/04/18 14:33:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replace.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

int countWords(const std::string &str)
{
	std::istringstream stream(str);
	std::string word;
	int count = 0;

	while (stream >> word)
		++count;

	return (count);
}

std::string *split(const std::string& str, char delimiter, int nbWord)
{
	size_t start = 0;
	size_t end = str.find(delimiter);
	std::string	*tokens = new std::string[nbWord];
	int tokenCount = 0;

	while (end != std::string::npos && tokenCount < nbWord)
	{
		tokens[tokenCount++] = str.substr(start, end - start);
		start = end + 1;
		end = str.find(delimiter, start);
	}

	if (tokenCount < nbWord && start < str.length())
		tokens[tokenCount++] = str.substr(start);

	return (tokens);
}

void  replaceStr(std::string *matrix, std::string &search, std::string &replace, int nbWords, std::ofstream &file)
{
	for (int i = 0; i < nbWords; i++)
	{
		if (matrix[i] == search)
			matrix[i] = replace;
		file << matrix[i] << " ";
	}
	file << std::endl;
}

void	replaceLines(std::string filename, std::string search, std::string replace)
{
	int	fileLines = countLines(filename);
	int	i = 0;

	std::string *allLines = getAllLines(filename);
	std::ofstream file(filename.c_str());
	if (!file)
	{
		std::cerr
					<< "Error in file: "
					<< filename
					<< " while opening and/or writing" <<
		std::endl;
		delete []allLines;
		return ;
	}

	while (i < fileLines)
	{
		int nbWords = countWords(allLines[i]);
		std::string *str = split(allLines[i], ' ', nbWords);

		replaceStr(str, search, replace, nbWords, file);

		delete []str;
		++i;
	}
	delete []allLines;
	file.close();
}
