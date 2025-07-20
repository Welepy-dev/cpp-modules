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

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{ std::cout << "PresidentialPardonForm parametized constructor called" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm( ) { } 

void	PresidentialPardonForm::action() const
{
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}


