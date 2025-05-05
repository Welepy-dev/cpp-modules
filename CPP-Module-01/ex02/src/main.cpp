/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:13:53 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/05 13:31:46 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "String's Address: "		<< &brain		<< std::endl;
	std::cout << "Pointer's Address: "		<< &stringPTR	<< std::endl;
	std::cout << "Reference's Address: "	<< &stringREF	<< std::endl;

	std::cout << "String's Value: "			<< brain		<< std::endl;
	std::cout << "Pointer's Value: "		<< *stringPTR	<< std::endl;
	std::cout << "Reference's Value: "		<< stringREF	<< std::endl;
}

/*
	this assignment was made to learn what a reference and a pointer is
	pointers are a concept learnt with C and their definition didnt change.
	while pointers are variables that store the addres of the variable they are pointing to
	references are like aliases for existing variables.
	when declaring a reference like:
	int &ref = a;
	a and ref both refer to the same thing so it means that if we alter one, it changes the value for both
*/