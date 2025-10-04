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
		~Array(void) { delete[] _array; };

		unsigned size(void) const { return (_size); };

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

	private:
		T			*_array;
		unsigned int	_size;
};

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

// Const version (for const arrays)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template<typename T>
Array<T>::Array(const Array<T> &other): _array(new T[other._size]) , _size(other._size)
{
	std::cout << "Array Copy constructor called" << std::endl;

	for (unsigned int i = 0; i < _size; ++i)
		_array[i] = other._array[i];
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
	return (*this);
}

// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.

#endif
