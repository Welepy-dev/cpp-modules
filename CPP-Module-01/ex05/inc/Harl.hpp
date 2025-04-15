/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:39:07 by welepy            #+#    #+#             */
/*   Updated: 2025/04/09 22:00:50 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:
		void complain(std::string level);
		
		Harl();
		~Harl();
	
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif // !HARL_HPP

