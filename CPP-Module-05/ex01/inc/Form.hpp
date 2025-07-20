/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:53:10 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/13 22:10:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureucrat;

class Form
{
	public:
		~Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		Form(std::string name, int signGrade, int executeGrade);

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
				GradeTooHighException(const std::string &msg): message(msg) { }
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

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif // !FORM_HPP
