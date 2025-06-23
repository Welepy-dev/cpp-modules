/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:53:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 16:41:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/GradeTooLowException.hpp"
#include "../inc/GradeTooHighException.hpp"

Form::Form(void)
{
	std::cout << "Form's Default constructor called" << std::endl;
}

Form::Form(std::string name, int isSigned, int signGrade, int executeGrade): _name(name), _isSigned(isSigned), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1) {
		throw GradeTooHighException("Grade is higher than 1!");
	}

	if (_signGrade > 150) {
		throw GradeTooHighException("Grade is higher than 1!");
	}
}

Form::Form(const Form &other)
{
	std::cout << "Form's copy constructor called" << std::endl;

	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form's copy assignment constructor called" << std::endl;
	this->name = other.name;
}
