/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:30 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 16:21:15 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    this->name = "Default";
    ClapTrap::name = this->name + "_clap_name";
    this->hitPoints = 100;         // From FragTrap
    this->energyPoints = 50;       // From ScavTrap
    this->attackDamage = 30;       // From FragTrap
    std::cout << "DiamondTrap default constructor called\n";
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap named constructor called\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called\n";
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

// Overridden attack from ScavTrap
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

// Special function
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap()
{
    this->name = "Default";
    ClapTrap::name = this->name + "_clap_name";
    this->hitPoints = 100;         // From FragTrap
    this->energyPoints = 50;       // From ScavTrap
    this->attackDamage = 30;       // From FragTrap
    std::cout << "DiamondTrap default constructor called\n";
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name)
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap named constructor called\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called\n";
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

// Overridden attack from ScavTrap
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

// Special function
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

