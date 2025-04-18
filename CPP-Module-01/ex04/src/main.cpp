/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:26:53 by welepy            #+#    #+#             */
/*   Updated: 2025/04/18 14:13:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replace.hpp"

int	main(int ac, char **av)
{
	std::string replaceName;
	std::string fileName;

	if (ac == 4)
	{
		fileName = av[1];
		std::ifstream inFile(fileName.c_str());
		if (!inFile)
		{
			std::cerr << "Error opening file!" << std::endl;
			inFile.close();
			return(EXIT_FAILURE);
		}
		inFile.close();
		replaceName = copyUntilChar(fileName, '.');
		replaceName.append(".replace");
		copyFile(replaceName, fileName);
		if (std::string(av[2]) != std::string(av[3]))
			replaceLines(replaceName, av[2], av[3]);
	}
	else
	{
		std::cerr
					<< "Error: Wrong input"
					<< std::endl
					<< "Right input: ./replace <filename> <s1> <s2>" <<
		std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
