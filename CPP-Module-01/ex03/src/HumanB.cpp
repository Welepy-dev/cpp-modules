/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/18 10:42:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include <iostream>
#include <string>

void  HumanB::attack(void)
{
	std::string str = weapon->getType();
	std::cout
				<< name
				<< " attacks with their "
				<< str <<
	std::endl;
}

HumanB::HumanB()
{
	weapon = NULL;
}
HumanB::~HumanB() {}

HumanB::HumanB(std::string Name)
{
	name = Name;
	weapon = NULL;
}

void  HumanB::setWeapon(Weapon &Weapon)
{
	weapon = &Weapon;
}
