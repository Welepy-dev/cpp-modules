/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:10:19 by marcsilv          #+#    #+#             */
/*   Updated: 2025/06/02 16:52:46 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Form.hpp"

class Bureucrat 
{
	public:
		Bureucrat(void);
		Bureucrat(std::string name, int grade);
		Bureucrat(const Bureucrat &other);
		Bureucrat &operator=(const Bureucrat &other);
		~Bureucrat(void);

		std::string getName(void) const;

		int		getGrade(void) const;
		void	setGrade(const int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);
	
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

		void	signForm(Form &form);

	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<(std::ostream &out, const Bureucrat &bureucrat);

#endif

