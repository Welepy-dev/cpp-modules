/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:22:03 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/05 14:51:11 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include <string>

const std::string &Weapon::getType(void)
{
	std::string &ref = type;
	return (ref);
}

void  Weapon::setType(std::string name)
{
	type = name;
}

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string name)
{
	type = name;
}
