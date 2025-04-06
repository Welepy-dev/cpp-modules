/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:46:53 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/06 16:32:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie*	Zombie::zombieHorde(int N, std::string Name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(Name);
	
	return (horde);
}