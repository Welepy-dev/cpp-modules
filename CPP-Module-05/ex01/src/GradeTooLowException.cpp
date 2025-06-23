/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:36:33 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 13:07:00 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GradeTooLowException.hpp" 

const char *GradeTooLowException::what() const throw(){
	return message.c_str();
}

GradeTooLowException::~GradeTooLowException( ) throw(){ } 
