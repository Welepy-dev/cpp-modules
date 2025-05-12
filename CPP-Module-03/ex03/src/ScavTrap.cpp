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
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->guarding_gate = copy.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

void  ScavTrap::attack(const std::string &target)
{
  if (this->energyPoints)
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

void  ScavTrap::takeDamage(unsigned int amount)
{
  std::cout << "ScavTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
}

void  ScavTrap::beRepaired(unsigned int amount)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    std::cout
                    << "ScavTrap "
                    << this->name
                    << " is repairing "
                    << amount
                    << "points of damage!" << 
    std::endl;
  }
  else
    std::cout << "ScavTrap " << this->name << " has no energy points to be repaired" << std::endl;
}

void	ScavTrap::guardGate(void)
{
  this->guarding_gate *= -1;
	if (this->guarding_gate == false)
	{
		this->guarding_gate = true;
		std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
	}
	else
  {
    this->guarding_gate = false;
		std::cout << "ScavTrap " << this->name << " is already guarding the gate." << std::endl;
  }
}
