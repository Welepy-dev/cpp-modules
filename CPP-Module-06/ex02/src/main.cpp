/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:58:16 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/11 14:36:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base	*generate(void)
{
    std::time_t now = std::time(0);  // or std::time(NULL)
	Base *base;
	
	if (now % 3 == 0)
		base = new A;
	else if (now % 3 == 1)
		base = new B;
	else
		base = new C;
	return base;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type A identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type B identified" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type C identified" << std::endl;
	else
		std::cout << "Unknow type" << std::endl;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A identified" << std::endl;
		return;
	} catch (...) {
		std::cout << "Bad cast" << std::endl;
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (...) {
		std::cout << "Bad cast" << std::endl;
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (...) {
		std::cout << "Bad cast" << std::endl;
	}

}

int main() {

    for (int i = 0; i < 5; ++i) {
        Base* ptr = generate();       // Create a random instance
        identify(ptr);                // Identify by pointer
        identify(*ptr);               // Identify by reference
        std::cout << "--------------------------------\n";
        delete ptr;                   // Clean up
    }

    return 0;
}
