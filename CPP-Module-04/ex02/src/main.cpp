/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:49:17 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:59 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main() {
    // Animal a;          // ❌ Error: Cannot instantiate abstract class
    Dog d;                // ✅ OK
    d.makeSound();        // Output: Woof!
    return 0;
}
