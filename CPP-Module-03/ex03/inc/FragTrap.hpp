/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:06:21 by marcsilv          #+#    #+#             */
/*   Updated: 2025/05/12 16:20:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
  
    void  attack(const std::string &target);
    void  takeDamage(unsigned int amount);
    void  beRepaired(unsigned int amount);
    void  highFiveGuys(void);

  private:

};

#endif // !FLAGTRAP_HPP
