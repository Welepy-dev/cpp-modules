#include "../inc/Array.hpp"

Array::Array(void) { _array = new T; }
Array::~Array() { std::cout << "Array Destructor called" << std::endl; }
~Array() { delete[] _array; }

Array::Array(unsigned n): _size(n)
{
	_array = new T[_size];
	for (int i = 0; i < _size; i++)
		_array[i] = 0;
}

Array::Array(const Array &other): _size(other._size), data(new T[other._size])
{
	std::cout << "Array Copy constructor called" << std::endl;

	for (int i = 0; i < _size; ++i)
		_array[i] = _array.data[i];
	*this = other;
}

Array &Array::operator=(const Array &other)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		data = new T[_size];
		for (int i = 0; i < _size; ++i)
			_array[i] = _array.data[i];
	}
	return (*this);
}


// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.