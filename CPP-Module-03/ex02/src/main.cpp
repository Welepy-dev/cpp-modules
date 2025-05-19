/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:32:29 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 12:32:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/FragTrap.hpp"  // or where you define them

int main() {
    std::cout << "=== ClapTrap ===" << std::endl;
    ClapTrap ct("CL4P-TP");
    ct.attack("target A");
    ct.takeDamage(5);
    ct.beRepaired(3);
    std::cout << std::endl;

    std::cout << "=== ScavTrap ===" << std::endl;
    ScavTrap st("SC4V-TP");
    st.attack("target B");
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();
    st.guardGate();
    std::cout << std::endl;

    std::cout << "=== FragTrap ===" << std::endl;
    FragTrap ft("FR4G-TP");
    ft.attack("target C");
    ft.takeDamage(50);
    ft.beRepaired(30);
    ft.highFiveGuys();
    std::cout << std::endl;

    std::cout << "=== Destruction ===" << std::endl;
    return 0;
}

