/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:03:57 by welepy            #+#    #+#             */
/*   Updated: 2025/03/26 20:42:39 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		void  Add(void);
		void  Search(void);
		void  exiting(void);
		Contact contacts[8];
		int index;
		int  is_full;
		PhoneBook() : index(0), is_full(1) {}
};

#endif
