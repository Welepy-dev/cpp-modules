/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:53:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/13 22:11:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Form.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureucrat.hpp"
#include "../inc/GradeTooLowException.hpp"
#include "../inc/GradeTooHighException.hpp"
#include <string>

AForm::AForm(std::string name, int signGrade, int executeGrade):
_name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "AForm's parametized constructor called" << std::endl;
	if (_signGrade < 1 || _executeGrade < 1) {
		throw GradeTooHighException("Grade is higher than 1!");
	}

	if (_signGrade > 150 || _executeGrade > 150) {
		throw GradeTooLowException("Grade is lower than 150!");
	}
}

AForm::AForm(const AForm &other): 
_name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "AForm's copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm's copy assignment constructor called" << std::endl;
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

AForm::~AForm(void) { }

std::string	AForm::getName(void) const { return (this->_name); }
bool		AForm::getIsSigned(void) const { return (this->_isSigned); }
int			AForm::getSignGrade(void) const { return (this->_signGrade); }
int			AForm::getExecuteGrade(void) const { return (this->_executeGrade); }

void		AForm::setIsSigned(int sign) { this->_isSigned = sign; }

void		AForm::beSigned(Bureucrat &bureucrat)
{
	if (bureucrat.getGrade() <= this->getSignGrade())
		this->setIsSigned(1);
	else
		throw GradeTooLowException("Grade is too low to sign!");
}

std::ostream& operator<<(std::ostream &out, const AForm &Aform)
{
	out << "AForm: " << Aform.getName()
	<< ", is " << ((Aform.getIsSigned() < 1) ? "not signed" : "signed")
	<< " with the execute grade of " << Aform.getExecuteGrade()
	<< " and a sign grade of " << Aform.getSignGrade() << std::endl;
	return (out);
}
