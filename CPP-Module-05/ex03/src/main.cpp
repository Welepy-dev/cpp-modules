/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:48:28 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/27 11:25:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureucrat high("HighRank", 1);
        Bureucrat mid("MidRank", 50);
        Bureucrat low("LowRank", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
        low.signForm(shrub);     // too low
        high.signForm(shrub);    // should succeed
        low.executeForm(shrub);  // too low
        high.executeForm(shrub); // should create the file

        std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
        mid.signForm(robo);      // sign should succeed
        mid.executeForm(robo);   // should fail, exec grade too low
        high.executeForm(robo);  // should succeed (50% success/fail)

        std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
        mid.signForm(pardon);    // too low to sign
        high.signForm(pardon);   // should succeed
        mid.executeForm(pardon); // too low to execute
        high.executeForm(pardon);// should succeed

    } catch (std::exception const & e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }
    return 0;
}
