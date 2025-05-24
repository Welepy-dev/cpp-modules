/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:16:14 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/24 12:44:35 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::~Dog()
{
  std::cout << "Dog's default destructor called" << std::endl;
  delete brain;
}

Dog::Dog()
{
  std::cout << "Dog's constructor called" << std::endl;
  this->type = "Dog";
  this->brain = new Brain();
}

void Dog::makeSound(void) const
{
  std::cout << "Bark" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
  std::cout << "Dog copy constructor called" << std::endl;
  brain = new Brain(*other.brain);  // deep copy
}

Dog &Dog::operator=(const Dog& other)
{
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &other)
  {
    Animal::operator=(other); // call base class assignment
    delete brain;             // free old brain
    brain = new Brain(*other.brain); // deep copy
  }
  return *this;
}

void Dog::setIdea(int index, const std::string& idea) { brain->setIdea(index, idea); }

std::string Dog::getIdea(int index) const { return brain->getIdea(index); }
