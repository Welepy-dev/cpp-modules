/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/18 09:16:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class	Zombie
{
	public:
		void	announce(void);
		
		void	setName(std::string);

		Zombie() ;
		~Zombie() ;
		Zombie(std::string name);
	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

Zombie*	zombieHorde(int N, std::string Name);

#endif
