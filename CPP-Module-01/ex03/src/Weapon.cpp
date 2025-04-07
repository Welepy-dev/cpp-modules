/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:03 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 14:57:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include <string>

const std::string &Weapon::getType(void)
{
  std::string &ref = this->type;
  return (ref);
}

void  Weapon::setType(std::string name)
{
  this->type = name;
}

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string name)
{
  this->type = name;
}
