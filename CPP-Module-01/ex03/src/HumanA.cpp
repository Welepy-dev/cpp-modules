
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Ay: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 14:23:13 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include <iostream>

void  HumanA::attack(void)
{
  std::cout
            << name 
            << " attacks with their "
            << weapon.getType() << 
  std::endl;
}

HumanA::~HumanA() {}

