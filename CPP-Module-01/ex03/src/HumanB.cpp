/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 15:51:57 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include <iostream>
#include <string>

void  HumanB::attack(void)
{
  std::string str = this->weapon->getType();
  std::cout << this->name << " attacks with their " << str << std::endl;
}

HumanB::HumanB() {}
HumanB::~HumanB() {}

HumanB::HumanB(std::string name)
{
  this->name = name;
  this->weapon = NULL;
}

void  HumanB::setWeapon(Weapon *weapon)
{
  this->weapon = &weapon;
}
