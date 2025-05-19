/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:36:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 12:48:35 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;

  hitPoints = 10;
  energyPoints = 10;
  attackDamage = 0;
  this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;

  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
  {
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    this->name = other.name;
  }
  return (*this);
}

void  ClapTrap::attack(const std::string &target)
{
  if (this->energyPoints && this->hitPoints)
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
  if (!hitPoints)
  {
    std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
    return ;
  }
  hitPoints -= amount;
  if (hitPoints < 0) hitPoints = 0;
  std::cout 
                  << "ClapTrap " 
                  << name 
                  << " has taken " 
                  << amount 
                  << " points of damage!" 
                  << " remaining HP: "
                  << hitPoints << 
  std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    hitPoints += amount;
    std::cout
                    << "ClapTrap "
                    << this->name
                    << " is repairing "
                    << amount
                    << " points of damage!"
                    << " total HP: "
                    << hitPoints <<
    std::endl;
  }
  else
    std::cout << "ClapTrap " << this->name << " has no energy points to be repaired" << std::endl;
}
