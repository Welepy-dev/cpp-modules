/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:36:15 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/21 15:10:18 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T &t, int i) { return (std::find(t.begin(), t.end(), i)); }
