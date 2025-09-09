/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:11:40 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/07 16:42:17 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

//have to verify if have a letter that I dont find
//if it starts with a dot
// if has multimple dots
//in the case of +42? or -42?
//check mixed stuff

/*bool	checkNums(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		if(!std::isdigit(str[i]))
			return (false);
	return (true);
}*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));
	return (0);
}
