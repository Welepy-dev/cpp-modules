/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:36:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 13:43:27 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap name constructor called" << std::endl;

  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
  this->name = name;
}

ClapTrap::ClapTrap()
{
  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;

  hitPoints = other.hitPoints;
  energyPoints = other.energyPoints;
  attackDamage = other.attackDamage;
  this->name = other.name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
  if (this != &other)
  {
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    this->name = other.name;
  }
  return (*this);
}

void  ClapTrap::attack(const std::string &target)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    std::cout
                    << "ClapTrap "
                    << this->name
                    << " attacks "
                    << target 
                    << " causing "
                    << this->attackDamage
                    << " points of damage!" << 
    std::endl;
  }
  else
    std::cout << "ClapTrap " << this->name << " has no energy points to attack" << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    std::cout
                    << "ClapTrap "
                    << this->name
                    << " is repairing "
                    << amount
                    << "points of damage!" << 
    std::endl;
  }
  else
    std::cout << "ClapTrap " << this->name << " has no energy points to be repaired" << std::endl;
}
