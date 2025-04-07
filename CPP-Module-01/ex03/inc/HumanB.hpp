/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:45:03 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 15:50:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB
{
  public:
    HumanB();
    ~HumanB();
    HumanB(std::string name);

    void  setWeapon(Weapon weapon);
    std::string name;
    Weapon  *weapon;
    void  attack(void);
  private:
  
};

#endif
