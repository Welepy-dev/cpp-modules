/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:25:38 by marcilsv          #+#    #+#             */
/*   Updated: 2025/04/06 16:32:49 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	public:
		void	setName(std::string name);
		void	announce(void);
		Zombie	*newZombie(std::string name);
		void	randomChump(std::string name);
		Zombie*	zombieHorde(int N, std::string Name);
		Zombie() ;
		~Zombie() ;
	private:
		std::string	name;
};

#endif
