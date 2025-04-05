/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcilsv <marcsilv@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/05 19:00:01 by marcilsv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int int main(void)
{
  Zombie  zombie;

  zombie.name = "zombie";
  zombie.announce();

  Zombie  chump = zombie.newZombie("Chump");
  
  chump.randomChump("new Chump");

  return (0);
}

