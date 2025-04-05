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

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

using namespace std;

class Zombie {
public:
  void  announce(void);
  Zombie  *newZombie(string name);
  void  randomChump(string name);
  Zombie();
  ~Zombie();
private:
  string  name;
};

Zombie::Zombie() {
}

Zombie::~Zombie() {
}

#endif
