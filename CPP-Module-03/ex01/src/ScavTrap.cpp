/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:33:52 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 13:46:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  guarding_gate = 0;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  this->name = name;
  guarding_gate = 0;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
  ClapTrap::operator=(src);
  guarding_gate = src.guarding_gate;
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->guarding_gate = copy.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

void  ScavTrap::attack(const std::string &target)
{
  if (this->energyPoints && this->hitPoints)
  {
    this->energyPoints--;
    std::cout
                    << "ScavTrap "
                    << this->name
                    << " attacks "
                    << target 
                    << " causing "
                    << this->attackDamage
                    << " points of damage!" << 
    std::endl;
  }
  else
    std::cout << "ScavTrap " << this->name << " has no energy points to attack" << std::endl;
}

void ScavTrap::guardGate()
{
    if (!guarding_gate)
    {
        guarding_gate = true;
        std::cout << "ScavTrap " << name << " has entered Gate keeper mode." << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << name << " is already guarding the gate." << std::endl;
    }
}

