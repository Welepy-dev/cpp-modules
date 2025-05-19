/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:52:38 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 12:52:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

int main() {
    DiamondTrap d1("Gem");

    d1.attack("Target1");
    d1.whoAmI();
    d1.takeDamage(40);
    d1.beRepaired(20);

    return 0;
}

