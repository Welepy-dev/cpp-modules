/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:58:28 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 13:04:05 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

# include <exception>
# include <string>

class GradeTooLowException: public std::exception 
{
	public:
		GradeTooLowException(const std::string &msg): message(msg) { };
		virtual const char *what() const throw();
		virtual ~GradeTooLowException() throw();
	
	private:
	std::string message;
		
};

#endif // !GRADETOOLOWEXCEPTION_HPP
