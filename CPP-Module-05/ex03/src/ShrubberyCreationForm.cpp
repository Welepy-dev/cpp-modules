/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:42:06 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/26 23:18:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{ std::cout << "ShrubberyCreationForm parametized constructor called" << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm( ) { } 

void	ShrubberyCreationForm::execute(Bureucrat const & executor) const
{
	if (!this->getIsSigned())
		throw Bureucrat::GradeTooLowException("Form is not signed!");
	if (executor.getGrade() > this->getExecuteGrade())
		throw Bureucrat::GradeTooHighException("Grade is too low to execute!");
	std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
	
	if (!file) { std::cerr << "Error opening " << filename << std::endl ; return ; }

	for (int i = 0; i < 5; i++)
	{
		file <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
	std::endl;
	}
    file.close(); // always good practice
}

