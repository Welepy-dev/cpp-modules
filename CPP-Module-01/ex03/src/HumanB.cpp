/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/15 15:27:11 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include <iostream>
#include <string>

void  HumanB::attack(void)
{
  std::string str = weapon->getType();
  std::cout << name << " attacks with their " << str << std::endl;
}

HumanB::HumanB() {}
HumanB::~HumanB() {}

HumanB::HumanB(std::string name)
{
  name = name;
  weapon = NULL;
}

void  HumanB::setWeapon(Weapon &weapon)
{
  weapon = &weapon;
}
