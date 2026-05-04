/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:19:26 by marcsilv          #+#    #+#             */
/*   Updated: 2026/05/04 13:23:50 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include <exception>

class RPN {
	public:
		RPN(const char *expr);
		~RPN();

		void		calculate(void);

	private:
		std::string			_expr;
		std::stack<short>	_stack;
		int					_result;
		
		short				get_top();
		int					char_to_int(char c);
};


#endif
