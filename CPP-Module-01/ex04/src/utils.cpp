/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:16:10 by welepy            #+#    #+#             */
/*   Updated: 2025/05/05 15:33:47 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replace.hpp"

void	copyFile(std::string dstName, std::string src)
{
	std::ofstream dstFile(dstName.c_str());
	if (!dstFile)
		std::cerr
					<< "Error in file: "
					<< dstName
					<< " while opening and/or writing" <<
		std::endl;

	std::string	*allLines = getAllLines(src);

	for (int i = 0; i < countLines(src); ++i)
		 dstFile << allLines[i] << std::endl;

	delete[] allLines;
	dstFile.close();
}

std::string	*getAllLines(std::string filename)
{
	int	lineCount = countLines(filename);

	std::string *lines = new std::string[lineCount];
	std::ifstream file(filename.c_str());

	for (int i = 0; i < lineCount && std::getline(file, lines[i]); ++i)
		;

	return (lines);
}

int	countLines(const std::string &filename)
{
	int lineCount = 0;

	std::ifstream inFile(filename.c_str());

	std::string line;

	while (std::getline(inFile, line))
		++lineCount;

	inFile.close();

	return (lineCount);
}

std::string	copyUntilChar(const std::string &input, char delimiter)
{
	size_t pos = input.find(delimiter);

	if (pos == std::string::npos)
		return (input);
	return (input.substr(0, pos));
}
