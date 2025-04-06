/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/06 17:01:36 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie	zombie;
	int	N = 500;

	Zombie	*Horde = zombie.zombieHorde(N, "Horder");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie nb: " << i + 1 << ": ";
		Horde[i].announce();
	}

	return (0);
}
