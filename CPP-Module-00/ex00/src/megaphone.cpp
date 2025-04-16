/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:15:55 by welepy            #+#    #+#             */
/*   Updated: 2025/04/16 14:11:59 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNREADABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; j < strlen(av[i]); j++)
				if (islower(av[i][j])) av[i][j] = toupper(av[i][j]);
			std::cout << av[i];
		}
	}
	std::cout << std::endl;
	return (0);
}
