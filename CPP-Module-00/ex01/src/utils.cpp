/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:20:22 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/15 17:27:32 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

# include <cctype>

bool	isAllNum(std::string str)
{
	if (str.empty()) return (false);

	long unsigned int	i = 0;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string	strtrim(const std::string &str, const std::string &whitespace)
{
	size_t start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of(whitespace);
	return str.substr(start, end - start + 1);
}