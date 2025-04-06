/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/06 16:27:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main(void)
{
	Zombie	zombie;


	Zombie	*chump = zombie.newZombie("Chump");
	chump->announce();
	
	chump->randomChump("new Chump");

	return (0);
}
/*
	this assignment was to teach us the difference between allocating in the heap, vs allocating memory on the stack
	to allocate memory on the stack we need to know how much memory is allocated on compile time,
	sometimes it will be unclear how much memory we will need at compile time, and the heap help us with that
	so, when we declare a variable like:
	int x = 10;
	we are allocating exactly 4 bytes on the stack
	and when declaring a variable like:
	int	*n = new int(5)
	it stores in the heap
	the main differences are in their lifetime, size and managing
*/
