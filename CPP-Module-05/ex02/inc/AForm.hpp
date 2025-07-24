/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:53:10 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/20 14:48:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <ctime>
# include <stdio.h>

class Bureucrat;

class AForm
{
	public:
		~AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		AForm(std::string name, int signGrade, int executeGrade);
		
		virtual void	execute(Bureucrat & executor) const = 0;

		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				setIsSigned(int sign);

		void				beSigned(Bureucrat &bureucrat);

		class GradeTooHighException: public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooHighException(const std::string &msg): message(msg) { };
				virtual const char *what() const throw() { return message.c_str(); };
				virtual ~GradeTooHighException() throw() { };
				void instantiate(int grade) { if (grade < 1) { throw GradeTooHighException("Grade is too High!"); } }
		};

		class GradeTooLowException: public std::exception
		{
			private:
				std::string message;
			public:
				GradeTooLowException(const std::string &msg): message(msg) { }
				virtual const char *what() const throw() { return message.c_str(); };
				virtual ~GradeTooLowException() throw() { };
				void instantiate(int grade) { if (grade > 150) { throw GradeTooLowException("Grade is too Low!"); } }
		};

	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif // !FORM_HPP
