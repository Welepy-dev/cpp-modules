/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:09:58 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/26 23:18:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{ std::cout << "PresidentialPardonForm parametized constructor called" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm( ) { } 

void	PresidentialPardonForm::execute(Bureucrat const & executor) const
{
	if (!this->getIsSigned())
		throw Bureucrat::GradeTooLowException("Form is not signed!");
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureucrat::GradeTooHighException("Grade is too low to execute!");
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

