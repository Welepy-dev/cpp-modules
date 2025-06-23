/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:48:28 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 13:09:32 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureucrat.hpp"
#include <exception>
#include <iostream>

int main () {
	
	Bureucrat  a("jose", 1);
	Bureucrat	b("burocrata", 150);
	try {
		a.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "exception met" << std::endl;
	}
	try {
	b.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "second exception met"	<< std::endl;
	}
	return 0;
}
