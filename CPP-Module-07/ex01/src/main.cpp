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
void printElem(U &x)
{
    std::cout << x << std::endl;
}

// A function that mutates ints (must be used with non-const int arrays)
void incrementInt(int &x)
{
    ++x;
}

int main()
{
    int arr[] = {1, 2, 3};
    const std::size_t n = 3;

    iter(arr, n, printElem);   // prints 1 2 3 (each on its own line)

    iter(arr, n, incrementInt);     // increments arr elements in-place

    return 0;
}
