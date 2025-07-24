/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:23:01 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/20 17:17:07 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{ std::cout << "RobotomyRequestForm parametized constructor called" << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm( ) { } 

void	RobotomyRequestForm::execute(Bureucrat & executor) const
{
	time_t sec = time(NULL);
	if (!this->getIsSigned() || (this->getSignGrade() >= executor.getGrade()) || executor.getGrade() < 1)
		throw Bureucrat::GradeTooLowException("Grade Is Too Low!");
	else if (executor.getGrade() > 150)
		throw Bureucrat::GradeTooHighException("Grade is too high!");

	std::cout << " ** Drilling noises ** " << std::endl;
	if (sec % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "the robotomy has failed" << std::endl;
}

