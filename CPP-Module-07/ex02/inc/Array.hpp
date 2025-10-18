/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:54:49 by marcsilv          #+#    #+#             */
/*   Updated: 2025/10/18 14:18:05 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <cstring>
# include <iostream>

template <typename T>
class	Array
{
	public:
		Array(void): _array(NULL), _size(0) { };
		Array(unsigned int n): _array(new T[n]()), _size(n) { }; // the _array(new T[n]() works the same way as std::memset(_array, 0, _size); )
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void) {
			if (_array)
				delete[] _array;
		};

		unsigned size(void) const { return (_size); };

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

	private:
		T				*_array;
		unsigned int	_size;
};

template<typename T>
Array<T>::Array(const Array<T> &other)
{
    this->_size = other._size;
    if (this->_size > 0)
        this->_array = new T[this->_size];
    else
        this->_array = NULL;

    for (unsigned int i = 0; i < this->_size; ++i)
        this->_array[i] = other._array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] this->_array;               // no need to check for nullptr before delete[]
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

// Const version (for const arrays)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.

#endif
