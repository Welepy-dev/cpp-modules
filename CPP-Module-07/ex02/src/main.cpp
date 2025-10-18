/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.f4>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:27:33 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/04 18:40:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main() {
    std::cout << "=== Basic construction tests ===" << std::endl;

    // Empty array
    Array<int> a;
    std::cout << "Empty array size: " << a.size() << std::endl;

    // Array of 5 ints
    Array<int> b(5);
    std::cout << "Array of 5 ints created. Size: " << b.size() << std::endl;

    // Show default initialization
    std::cout << "Contents of b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Value assignment tests ===" << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;
    std::cout << "Modified b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Copy constructor test ===" << std::endl;
    Array<int> c(b); // deep copy
    std::cout << "Copy of b created. Contents: ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "Modifying c[0] = 999..." << std::endl;
    c[0] = 999;
    std::cout << "c[0]: " << c[0] << ", b[0]: " << b[0] << std::endl;

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    Array<int> d;
    d = b;
    std::cout << "Assigned d = b. Contents: ";
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
    std::cout << "\n=== Const correctness test ===" << std::endl;
    const Array<int> e(b);
    std::cout << "Const copy contents: ";
    for (unsigned int i = 0; i < e.size(); i++)
        std::cout << e[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Template type test (strings) ===" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "Hello";
    strs[1] = "World";
    strs[2] = "!";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
    std::cout << std::endl;

    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}
