/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:49:17 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:59 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  
  meta->makeSound();

  delete meta;
  delete j;
  delete i;
  return 0;
}
