/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:11:23 by welepy            #+#    #+#             */
/*   Updated: 2025/04/15 15:38:44 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
		std::string	nickname;
		std::string	darkest_secret;
	public:
		Contact();
		~Contact();

		std::string	&getFirstName(void);
		std::string	&getLastName(void);
		std::string	&getPhoneNumber(void);
		std::string	&getNickname(void);
		std::string	&getDarkestSecret(void);

		void		setNickname(std::string str);
		void		setLastName(std::string str);
		void		setFirstName(std::string str);
		void		setPhoneNumber(std::string str);
		void		setDarkestSecret(std::string str);
};

#endif
