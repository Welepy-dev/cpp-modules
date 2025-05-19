/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:10:30 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 13:00:04 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// DiamondTrap.cpp

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("Default") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap default constructor called\n";
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap named constructor called\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called\n";
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called\n";
}

// Use ScavTrap's attack
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

// whoAmI method
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

