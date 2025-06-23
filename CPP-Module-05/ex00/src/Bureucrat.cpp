/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:45:08 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 13:07:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureucrat.hpp"
#include "../inc/GradeTooHighException.hpp"
#include "../inc/GradeTooLowException.hpp"

std::string Bureucrat::getName(void) const
{
  return (name);
}

void   Bureucrat::setGrade(const int grade)
{
  this->grade = grade;
}

int   Bureucrat::getGrade(void) const
{
  return (grade);
}

void  Bureucrat::incrementGrade(void)
{
	if (grade == 1) {
		throw GradeTooHighException("Grade at its highest!");
	}
	grade--;
}

void  Bureucrat::decrementGrade(void)
{
	if (grade == 150) {
		throw GradeTooLowException("Grade at its lowest!");
	}
  grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureucrat &bureucrat)
{
  out << bureucrat.getName() << ", bureucrat grade " << bureucrat.getGrade();
  return (out);
}

Bureucrat::Bureucrat(void) { std::cout << "Bureucrat's default constructor called" << std::endl; }
Bureucrat::~Bureucrat(void) { std::cout << "Bureucrat's default destructor called" << std::endl; }
Bureucrat::Bureucrat(std::string name, int grade): name(name), grade(grade)
{ std::cout << "Bureucrat's parametized constructor called" << std::endl; }

Bureucrat &Bureucrat::operator=(const Bureucrat &other)
{
  std::cout << "Bureucrat's Copy assignment operator called" << std::endl;
  if (this != &other)
  {
    this->name = other.name;
    this->grade = other.grade;
  }
  return (*this);
}

Bureucrat::Bureucrat(const Bureucrat &other)
{
  std::cout << "Bureucrat's copy constructor operator called" << std::endl;

  *this = other;
}

