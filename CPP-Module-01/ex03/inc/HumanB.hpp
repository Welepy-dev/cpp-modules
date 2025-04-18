/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:45:03 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/18 10:37:44 by codespace        ###   ########.fr       */
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
		HumanB(std::string Name);

		void  setWeapon(Weapon &Weapon);
		void  attack(void);
	
	private:
		std::string name;
		Weapon  *weapon;
	
};

#endif
