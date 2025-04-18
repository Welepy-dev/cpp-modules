/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/18 09:41:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *horde = zombieHorde(10, "Stan");

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Zombie nb: " << i + 1 << ": ";
		horde[i].announce();
	}

	delete[] horde;

	return (0);
}
