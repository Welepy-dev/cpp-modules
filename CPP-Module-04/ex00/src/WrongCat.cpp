
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:46:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:23:41 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::~WrongCat() { std::cout << "WrongCat's default destructor called" << std::endl; }

WrongCat::WrongCat()
{
  std::cout << "WrongCat's constructor called" << std::endl;
  this->type = "WrongCat";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
  std::cout << "WrongCat's Copy assignment operator called" << std::endl;
  if (this != &other)
    this->type = other.type;
  return (*this);
}

WrongCat::WrongCat(const WrongCat &other): Animal(other)
{
  std::cout << "WrongCat's copy constructor operator called" << std::endl;

  *this = other;
}

void WrongCat::makeSound(void) const
{
  std::cout << "Meow" << std::endl;
}
