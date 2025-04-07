/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:54:18 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/07 14:56:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
  private:
    std::string type;

  public:
    const std::string &getType(void);
    void  setType(std::string newType);

    Weapon();
    ~Weapon();
    Weapon(std::string name);
};

#endif
