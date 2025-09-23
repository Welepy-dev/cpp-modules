/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:11:40 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:17 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include <iostream>
#include "../inc/Data.hpp"

int	randomInRange(int min, int max) { return (min + (rand() % (max - min + 1))); }

int main(void)
{
	Data data(randomInRange(0, 127), randomInRange(-5000, 5000));

	Data *original = &data;

	uintptr_t raw = Serializer::serialize(original);

    // Deserialize -> Data*
	Data* restored = Serializer::deserialize(raw);
	if (restored == original)
	{
		std::cout << "Success! Pointers match.\n";
		std::cout << "Value: " << restored->getInteger() << std::endl;
	}
	else
		std::cout << "Error: Pointers do not match.\n";
	return (0);
}
