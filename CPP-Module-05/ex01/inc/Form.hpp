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

# include <string>

class Bureucrat;

class Form {
	public:
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string			getName(void) const;
		int					getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				setIsSigned(int sign);

		void				beSigned(Bureucrat &bureucrat);

	private:
		const std::string	_name;
		int					_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif // !FORM_HPP
