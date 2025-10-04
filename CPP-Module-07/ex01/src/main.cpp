/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:41 by codespace         #+#    #+#             */
/*   Updated: 2025/10/04 07:56:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

// A generic print function template (takes element by const ref)
template <typename U>
void printElem(U x)
{
    std::cout << x << std::endl;
}

// A function that mutates ints (must be used with non-const int arrays)
void incrementInt(int x)
{
    ++x;
}

int main()
{
    int arr[] = {1, 2, 3};
    const std::size_t n = 3;

    // 1) Print in ts (printElem<int> is an instantiated function template)
    iter(arr, n, printElem);   // prints 1 2 3 (each on its own line)

    // 2) Mutate array elements
    iter<int>(arr, n, incrementInt);     // increments arr elements in-place
    iter(arr, n, printElem<int>);   // prints 2 3 4

    // 3) Strings (modifiable)
    std::string sarr[] = {"hi", "42"};

    // 4) const array: only functions taking const-ref or value allowed
    const int carr[] = {10, 20, 30};
    iter(carr, 3, printElem); // OK: printElem<int> takes const int&

    // iter(carr, 3, incrementInt); // ERROR: can't bind int& to const int

    return 0;
}
