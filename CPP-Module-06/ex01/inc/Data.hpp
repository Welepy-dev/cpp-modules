/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:00:54 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/19 16:11:51 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <string>

class Data
{
	public:
		Data(int i1, int i2);
		Data &operator=(const Data &other);
		Data(const Data &other);
		~Data();

		void			setName(std::string name);
		std::string		getName(void) const;

		void			setInteger(int integer);
		int				getInteger(void) const;

	private:
		std::string	name;
		int			integer;
};

#endif // !DATA_HPP
