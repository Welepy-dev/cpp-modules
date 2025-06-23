/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:36:33 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 12:38:38 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GradeTooHighException.hpp"

const char *GradeTooHighException::what() const throw(){
	return message.c_str();
}

GradeTooHighException::~GradeTooHighException( ) throw() { } 
