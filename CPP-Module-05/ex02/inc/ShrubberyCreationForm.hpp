/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/07/20 17:16:09 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();

		virtual void execute(Bureucrat & executor) const;
	
	private:
		const std::string _target;
		
};

#endif // !SHRUBBERYCREATIONFORM_HPP
