/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:03:57 by welepy            #+#    #+#             */
/*   Updated: 2025/04/15 18:04:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include	"Contact.hpp"

class PhoneBook
{
	private:
		Contact			contacts[8];
		int				index;
		int				is_full;

	public:
		PhoneBook();
		~PhoneBook();
		
		void			add(void);
		void			search(void);
		void			exiting(void);
		void			getContactInfo(int index);
};

#endif
