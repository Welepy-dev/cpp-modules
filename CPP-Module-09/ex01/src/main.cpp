/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:10:54 by codespace         #+#    #+#             */
/*   Updated: 2025/12/11 15:08:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Imprima algo valido" << std::endl;
		return (0);
	}
	try {
		/*
		<333dmsaklmdklsadmskalmlkdsadmsakladmsklamksdl
		asdmkalmsdmdkalsakdmls
		asdmklaksdmadmklsadsklmadsklmasdmlkmlmklkmlmkl
		amsdkllaskdmalskdmclkmdlask mcaskldml, hdsofadaskmltçl,sçldm,am
		mdklasdmaskldsamlk
		5555saaS142313213246654565464564654654
		4sasdas
		*/
		RPN	rpn(argv[1]);
		rpn.calculate();
	}	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return (0);
}
