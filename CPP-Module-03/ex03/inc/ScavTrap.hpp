/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:12:59 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/19 13:00:06 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
  
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();
  
    void  attack(const std::string &target);
    void  guardGate(void);

  private:
    int guarding_gate;
};

#endif // !ScavTrap
