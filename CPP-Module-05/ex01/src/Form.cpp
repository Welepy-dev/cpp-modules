/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:53:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/13 22:11:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Form.hpp"
#include "../inc/Bureucrat.hpp"
#include <string>

Form::Form(std::string name, int signGrade, int executeGrade):
_name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form's parametized constructor called" << std::endl;
	if (_signGrade < 1 || _executeGrade < 1) { throw GradeTooHighException("Grade is higher than 1!"); }

	if (_signGrade > 150 || _executeGrade > 150) { throw GradeTooLowException("Grade is lower than 150!" ); }
}

Form::Form(const Form &other): 
_name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form's copy assignment constructor called" << std::endl;
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

Form::~Form(void) { }

std::string	Form::getName(void) const { return (this->_name); }
bool		Form::getIsSigned(void) const { return (this->_isSigned); }
int			Form::getSignGrade(void) const { return (this->_signGrade); }
int			Form::getExecuteGrade(void) const { return (this->_executeGrade); }

void		Form::setIsSigned(int sign) { this->_isSigned = sign; }

void		Form::beSigned(Bureucrat &bureucrat)
{
	if (bureucrat.getGrade() <= this->getSignGrade())
		this->setIsSigned(1);
	else
		throw GradeTooLowException("Grade is too low to sign!");
}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName()
	<< ", is " << ((form.getIsSigned() < 1) ? "not signed" : "signed")
	<< " with the execute grade of " << form.getExecuteGrade()
	<< " and a sign grade of " << form.getSignGrade() << std::endl;
	return (out);
}
