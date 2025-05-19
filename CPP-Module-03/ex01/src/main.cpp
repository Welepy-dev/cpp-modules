/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:04:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 12:04:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main()
{
    std::cout << "Creating ScavTrap...\n";
    ScavTrap unit("GATE-9000");

    std::cout << "\n--- Combat Test ---\n";
    unit.attack("Intruder");
    unit.takeDamage(20);
    unit.beRepaired(10);  // Use inherited ClapTrap version unless overridden

    std::cout << "\n--- Gate Mode Test ---\n";
    unit.guardGate();
    unit.guardGate();  // Should say already guarding

    std::cout << "\nDestroying ScavTrap...\n";
    return 0;
}

