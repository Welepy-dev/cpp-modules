/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:27:57 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 10:28:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
    ClapTrap ct1("CL4P-TP");

    ct1.attack("Bandit");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
    ct1.takeDamage(12); // Overkill test
    ct1.attack("Skag"); // Should fail due to death
    ct1.beRepaired(3);  // Should fail due to death

    return 0;
}

