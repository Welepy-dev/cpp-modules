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
#include <iostream>

int main() {
    Bureucrat jose("Jose", 1);
    Bureucrat noob("Intern", 150);

    Form formA("TaxForm", 50, 75);

    std::cout << formA << std::endl;

    // Successful sign
    jose.signForm(formA);

    // Already signed test
    std::cout << formA << std::endl;

    // Failing sign (will throw)
    Form formB("SecretForm", 1, 1);
    noob.signForm(formB);  // should fail
}
