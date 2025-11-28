/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:40:57 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 15:10:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"   // Include your template function

int main()
{
    std::cout << "Testing std::vector<int>...\n";

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

	std::vector<int>::const_iterator it = easyfind(vec, 20);
	std::cout << "Found: " << *it << std::endl;

	std::cout << "Searching for 99...\n";
	it = easyfind(vec, 99);
	std::cout << "Found: " << *it << std::endl;

    std::cout << "\nTesting std::list<int>...\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);

	std::list<int>::iterator iterator = easyfind(lst, 15);
	std::cout << "Found: " << *iterator << std::endl;

	std::cout << "Searching for 42...\n";
	iterator = easyfind(lst, 43);
	std::cout << "Found: " << *it << std::endl;
	return 0;
}
