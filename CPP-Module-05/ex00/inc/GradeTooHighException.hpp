/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:40:15 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 12:38:08 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

# include <exception>
#include <string>

class GradeTooHighException: public std::exception
{
  public:
    GradeTooHighException(const std::string &msg): message(msg) {};
	virtual const char	*what() const throw();
    virtual ~GradeTooHighException() throw();

  private:
	std::string	message;
  
};

#endif // !GRADETOOHIGHEXCEPTION_HPP
