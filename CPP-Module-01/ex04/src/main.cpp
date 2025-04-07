/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:26:53 by welepy            #+#    #+#             */
/*   Updated: 2025/04/07 23:31:26 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{

	}
	else
	{
		std::cout << "Error: Wrong input" << std::endl;
		std::cout << "Right input: ./sed <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}
