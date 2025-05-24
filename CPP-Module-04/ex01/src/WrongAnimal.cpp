/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:52:27 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "WrongAnimal's default constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal's default destructor called" << std::endl; }

WrongAnimal::WrongAnimal(std::string type)
{
  std::cout << "WrongAnimal's named constructor called" << std::endl;
  this->type = type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
  std::cout << "WrongAnimal's Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
  std::cout << "WrongAnimal's copy constructor operator called" << std::endl;

  *this = other;
}

void WrongAnimal::makeSound(void) const
{
  std::cout << "Generic animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
  return this->type;
}
