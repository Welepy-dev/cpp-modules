/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:20:23 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/09 18:20:27 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class Serializer
{
	public:
		Serializer &operator=(const Serializer &other);
		~Serializer();

	private:
		Serializer();
		/*Serializer(const Serializer &other);*/
};

#endif // !DEBUG
