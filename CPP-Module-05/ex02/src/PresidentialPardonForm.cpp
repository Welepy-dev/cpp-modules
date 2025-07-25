/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:09:58 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/20 17:16:49 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{ std::cout << "PresidentialPardonForm parametized constructor called" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm( ) { } 

void	PresidentialPardonForm::execute(Bureucrat & executor) const
{
	if (!this->getIsSigned())
		throw Bureucrat::GradeTooLowException("Form is not signed!");
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureucrat::GradeTooHighException("Grade is too low to execute!");
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}


