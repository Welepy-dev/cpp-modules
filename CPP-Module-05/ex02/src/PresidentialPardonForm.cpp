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
	if (!this->getIsSigned() || (this->getSignGrade() >= executor.getGrade()) || executor.getGrade() < 1)
		throw Bureucrat::GradeTooLowException("Grade Is Too Low!");
	else if (executor.getGrade() > 150)
		throw Bureucrat::GradeTooHighException("Grade is too high!");
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}


