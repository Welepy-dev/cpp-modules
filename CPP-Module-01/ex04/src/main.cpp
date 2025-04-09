/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:26:53 by welepy            #+#    #+#             */
/*   Updated: 2025/04/09 14:58:17 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/replace.hpp"

#include <cstring>
#include <iostream>	

int	main(int ac, char **av)
{
	std::string replaceName;
	std::string fileName;

	if (ac == 4)
	{
		fileName = av[1];
		replaceName = copyUntilChar(fileName, '.');
		replaceName.append(".replace");
		copyFile(replaceName, fileName);
		if (strcmp(av[2], av[3]))
			replaceLines(fileName, av[2], av[3]);
	}
	else
	{
		std::cout << "Error: Wrong input" << std::endl;
		std::cout << "Right input: ./replace <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
