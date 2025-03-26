/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:15:55 by welepy            #+#    #+#             */
/*   Updated: 2025/03/26 09:44:30 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int	main(int ac, char **av)
{
	if (ac == 1)
		cout << "* LOUD AND UNREADABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; j < strlen(av[i]); j++)
				if (islower(av[i][j])) av[i][j] = toupper(av[i][j]);
			cout << av[i];
		}
	}
	cout << endl;
	return (0);
}

/*	This project was made to introduce me to Cpp and cpp related concepts
*	the first concept we use here is namespaces, which are containers that store names of types functions variables etc
*	whe use them to organize code into logical groups and preventing name collisions
*	
*	The second concept is objects, objects are data fields that have attributes and behavior
*	"cout" is an object that describes the console output
*	objects are units of code that represent classes
*	and finnaly, classes are template for creating objects*
*
*	The third
*/
