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

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

//search what is a uintptr_t, also how they differ from normal pointers in terms of bytes and shi
//
//Yes — you can use reinterpret_cast to convert a pointer to one type into a pointer to a different type (including your own structs).

//But ⚠️ you have to be very careful: doing this blindly can lead to undefined behavior if the memory layouts don’t match or if you access members in an invalid way.
