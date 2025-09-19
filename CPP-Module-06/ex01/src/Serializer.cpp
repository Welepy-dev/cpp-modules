/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:07:53 by marcsilv          #+#    #+#             */
/*   Updated: 2025/09/19 13:10:23 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

/*
 * Unlike static_cast (which does some type checking and conversions), reinterpret_cast is a low-level, unsafe cast. It doesn’t change the actual bits of the value — it just changes how those bits are interpreted.
 *
 * */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

//search what is a uintptr_t, also how they differ from normal pointers in terms of bytes and shi
//
