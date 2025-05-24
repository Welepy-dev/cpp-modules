/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:52:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <string>

Animal::Animal() { std::cout << "Animal's default constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal's default destructor called" << std::endl; }

Animal::Animal(std::string type)
{
  std::cout << "Animal's named constructor called" << std::endl;
  this->type = type;
}

Animal &Animal::operator=(const Animal &other)
{
  std::cout << "Animal's Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return (*this);
}

Animal::Animal(const Animal &other)
{
  std::cout << "Animal's copy constructor operator called" << std::endl;

  *this = other;
}

void Animal::makeSound(void) const
{
  std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
  return this->type;
}
