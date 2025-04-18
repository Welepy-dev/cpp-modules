/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:46:53 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/18 09:23:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*newZ = new Zombie(name);
	return (newZ);
}

void	randomChump(std::string name)
{
	Zombie	chump(name);

	chump.announce();
}

Zombie*	zombieHorde(int N, std::string Name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(Name);
	
	return (horde);
}
