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

#include <../inc/Zombie.hpp>
#include <string>

void  Zombie::announce(void)
{
  cout << name << endl;
  cout << "BraiiiiiiinnnzzzZ" << endl;
}

Zombie  *Zombie::newZombie(std::string name)
{
  Zombie  newZ = malloc(sizeof(Zombie *));
  newZ.name = name;
  return (newZ);
}

void  Zombie::randomChump(std::string name)
{
  Zombie  chump;

  chump.name = name;
  chump.announce();
}
