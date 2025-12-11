/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:00:20 by codespace         #+#    #+#             */
/*   Updated: 2025/12/11 15:08:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN(const char *expr) {
	this->_expr = expr;
}

RPN::~RPN(void) { }

void RPN::calculate(void) {
	if (this->_expr.find_first_not_of("0123456789/*-+") != std::string::npos) {
		std::cout << "Error." << std::endl;
		return ;
	}
}
