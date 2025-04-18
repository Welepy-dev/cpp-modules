/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:50:47 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/18 15:16:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon  &weapon;

	public:
		HumanA(std::string Name, Weapon &Weapon): name(Name), weapon(Weapon) {}
		~HumanA();

		void  attack(void);
};

#endif // !HUMANA_HPP
