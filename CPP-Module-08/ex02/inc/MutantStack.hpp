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
# include <stack>
# include <iostream>

template<typename T>
class MutantStack: public std::stack<T> {


	public:
		MutantStack() { };
		MutantStack(const MutantStack &other):std::stack<T>(other) { };
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}; 
		~MutantStack() { };

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return (this->c.begin()); };
		iterator end()   { return (this->c.end());   };
	
};

#endif // !MUTANTSTACK_HPP
