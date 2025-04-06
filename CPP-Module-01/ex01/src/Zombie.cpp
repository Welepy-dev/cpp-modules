/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/06 16:30:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie() {}
Zombie::~Zombie() {}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*Zombie::newZombie(std::string name)
{
	Zombie	*newZ = new Zombie;
	(*newZ).name = name;
	return (newZ);
}

void	Zombie::randomChump(std::string name)
{
	Zombie	chump;

	chump.name = name;
	chump.announce();
}

