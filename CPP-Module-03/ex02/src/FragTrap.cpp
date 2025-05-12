/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:11:34 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 15:14:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  this->name = name;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return *this;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

void  FragTrap::attack(const std::string &target)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    std::cout
                    << "FragTrap "
                    << this->name
                    << " attacks "
                    << target 
                    << " causing "
                    << this->attackDamage
                    << " points of damage!" << 
    std::endl;
  }
  else
    std::cout << "FragTrap " << this->name << " has no energy points to attack" << std::endl;
}

void  FragTrap::takeDamage(unsigned int amount)
{
  std::cout << "FragTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
}

void  FragTrap::beRepaired(unsigned int amount)
{
  if (this->energyPoints)
  {
    this->energyPoints--;
    std::cout
                    << "FragTrap "
                    << this->name
                    << " is repairing "
                    << amount
                    << "points of damage!" << 
    std::endl;
  }
  else
    std::cout << "FragTrap " << this->name << " has no energy points to be repaired" << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->name << ": You want a high five?." << std::endl;
}
