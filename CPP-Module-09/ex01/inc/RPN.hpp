/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:14:47 by codespace         #+#    #+#             */
/*   Updated: 2025/12/12 10:43:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include <exception>

class RPN
{
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