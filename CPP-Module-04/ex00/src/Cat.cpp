/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:46:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:23:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::~Cat() { std::cout << "Cat's default destructor called" << std::endl; }

Cat::Cat()
{
  std::cout << "Cat's constructor called" << std::endl;
  this->type = "Cat";
}

Cat &Cat::operator=(const Cat &other)
{
  std::cout << "Cat's Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return (*this);
}

Cat::Cat(const Cat &other): Animal(other)
{
  std::cout << "Cat's copy constructor operator called" << std::endl;

  *this = other;
}

void Cat::makeSound(void) const
{
  std::cout << "Meow" << std::endl;
}
