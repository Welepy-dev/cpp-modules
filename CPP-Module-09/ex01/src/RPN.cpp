/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:00:20 by codespace         #+#    #+#             */
/*   Updated: 2025/12/12 10:42:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN(const char *expr) {
	this->_expr = expr;
	this->_result = 0;
}

RPN::~RPN(void) { }

int RPN::char_to_int(char c) {
	std::istringstream iss (std::string(1, c));
	
	int result;
	iss >> result;
	
	return (result);
}

short RPN::get_top() {
	short value = this->_stack.top();
	this->_stack.pop();
	return (value);
}

void RPN::calculate(void) {
	if (this->_expr.find_first_not_of("0123456789/*-+") != std::string::npos) {
		std::cerr << "Error." << std::endl;
		return ;
	}
	for (short i = 0; i < static_cast<short>(this->_expr.length()); i++) {
		if ((this->_expr[i] >= '0') && (this->_expr[i] <= '9')) {
			this->_stack.push(this->char_to_int(this->_expr[i]));
		} else {
			if (this->_stack.size() != 2) {
				std::cerr << "Error." << std::endl;
				return ;
			}
			switch (this->_expr[i])
			{
				case '+':
					this->_result = this->get_top();
				case '-':
				/* code */
					break;
				case '*':
					/* code */
					break;
				case '/':
				/* code */
					break;
				default:
					std::cerr << "Error." << std::endl;
					return ;
			}
		}
	}
}
