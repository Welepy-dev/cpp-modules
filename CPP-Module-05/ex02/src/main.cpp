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
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main() {
    Bureucrat alice("Alice", 1); // High enough to do anything

    ShrubberyCreationForm form("home");

    alice.signForm(form);
    alice.executeForm(form);  // Should create file "home_shrubbery"

    RobotomyRequestForm robo("Bender");
    alice.signForm(robo);
    alice.executeForm(robo);

    PresidentialPardonForm pardon("Ford Prefect");
    alice.signForm(pardon);
    alice.executeForm(pardon);

    return 0;
}
