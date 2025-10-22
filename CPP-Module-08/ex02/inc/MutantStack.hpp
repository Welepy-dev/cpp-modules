/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:44 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 18:34:39 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

class MutantStack {
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other); 
		~MutantStack();
	
	private:
		
};

#endif // !MUTANTSTACK_HPP
