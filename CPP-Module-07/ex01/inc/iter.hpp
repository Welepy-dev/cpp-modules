/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:18:25 by codespace         #+#    #+#             */
/*   Updated: 2025/10/03 16:22:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>
# include <string>
/*
template <typename T>
T add(T a, T b) {
    return a + b;
}
*/

//int (*fp)(int, int);   // fp is a pointer to a function taking (int,int) and returning int


template <typename T>
void	iter(T *a, const size_t size, void(*f)(T t))
{
	for (size_t i = 0; i < size; i++)
		f(a[i]);
}
#endif
