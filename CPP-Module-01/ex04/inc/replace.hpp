/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy </var/spool/mail/welepy>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:14:50 by welepy            #+#    #+#             */
/*   Updated: 2025/04/09 17:03:30 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <cstdlib>
# include <string>

int countLines(const std::string &filename);

void  copyFile(std::string dstName, std::string src);

void	replaceLines(std::string filename, std::string search, std::string replace);

std::string	copyUntilChar(const std::string &input, char delimiter);

std::string	*getAllLines(std::string filename);

#endif
