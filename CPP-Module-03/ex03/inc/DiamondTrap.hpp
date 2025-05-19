
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:47:15 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 15:47:15 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./FragTrap.hpp"
# include "./ScavTrap.hpp"
# include <string>

class DiamondTrap: public FragTrap, public ScavTrap
{
  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();
  
    void whoAmI();
    void attack(const std::string &target);

  private:
    std::string name;  
};

#endif // !DIAMONDTRAP_HPP
