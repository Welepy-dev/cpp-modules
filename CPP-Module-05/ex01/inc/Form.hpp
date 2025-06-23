/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:53:10 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/23 16:35:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureucrat.hpp"
# include <string>

class Form {
	public:
		Form();
		Form(std::string name, int isSigned, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		int			getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		std::string	getName(void) const;

		void		setName(std::string name);
		void		setSignGrade(int grade);
		void		setExecuteGrade(int grade);
		void		setIsSigned(int grade);

		void		beSigned(Bureucrat &bureucrat);

	private:
		std::string _name;
		const int	_isSigned;
		const int	_signGrade;
		const int	_executeGrade;
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif // !FORM_HPP
