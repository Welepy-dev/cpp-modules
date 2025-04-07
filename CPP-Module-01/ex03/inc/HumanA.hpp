/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:50:47 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 15:41:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include "Weapon.hpp"

class HumanA
{
  public:
    HumanA(std::string name, Weapon &weapon):
            name(name), weapon(weapon) {}
    ~HumanA();

    std::string name;
    Weapon  &weapon;
    void  attack(void);
};

#endif // !HUMANA_HPP
