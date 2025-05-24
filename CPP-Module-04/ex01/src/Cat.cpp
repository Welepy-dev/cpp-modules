/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:46:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/24 12:44:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::~Cat()
{
  std::cout << "Cat's default destructor called" << std::endl;
  delete brain;
}

Cat::Cat()
{
  std::cout << "Cat's constructor called" << std::endl;
  this->type = "Cat";
  this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Cat copy constructor called" << std::endl;
  brain = new Brain(*other.brain);  // deep copy
}

Cat &Cat::operator=(const Cat& other)
{
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &other)
  {
    Animal::operator=(other); // call base class assignment
    delete brain;             // free old brain
    brain = new Brain(*other.brain); // deep copy
  }
  return *this;
}

void Cat::makeSound(void) const
{
  std::cout << "Meow" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) { brain->setIdea(index, idea); }

std::string Cat::getIdea(int index) const { return brain->getIdea(index); }
