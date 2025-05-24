/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:16:14 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:24:01 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::~Dog() { std::cout << "Dog's default destructor called" << std::endl; }

Dog::Dog()
{
  std::cout << "Dog's constructor called" << std::endl;
  this->type = "Dog";
}

Dog &Dog::operator=(const Dog &other)
{
  std::cout << "Dog's Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return (*this);
}

Dog::Dog(const Dog &other): Animal(other)
{
  std::cout << "Dog's copy constructor operator called" << std::endl;

  *this = other;
}

void Dog::makeSound(void) const
{
  std::cout << "Bark" << std::endl;
}
