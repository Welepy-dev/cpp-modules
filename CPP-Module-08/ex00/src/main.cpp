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

#include <iostream>
#include <vector>
#include <list>
#include "../inc/easyfind.hpp"   // Include your template function

int main()
{
    std::cout << "Testing std::vector<int>...\n";

    const std::vector<int> numbers;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try
    {
        std::vector<int>::const_iterator it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 99...\n";
        it = easyfind(vec, 99); // Should throw
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nTesting std::list<int>...\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found: " << *it << std::endl;

        std::cout << "Searching for 42...\n";
        it = easyfind(lst, 42); // Should throw
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
   return 0;
}
