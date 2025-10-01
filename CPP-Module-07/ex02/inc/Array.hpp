/*
template <class T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() { return value; }
};

*/
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class	Array
{
	public:
		Array(void);
		Array(unsigned n); // Tip: Try to compile int * a = new int(); then display *a.
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void);

	private:
}

/*

Develop a class template Array that contains elements of type T and that implements
 the following behavior and functions:
 • Construction with no parameter: Creates an empty array.
 • Construction with an unsigned int n as a parameter: Creates an array of n elements
 initialized by default.
 Tip: Try to compile int * a = new int(); then display *a.
 • Construction by copy and assignment operator. In both cases, modifying either the
 original array or its copy after copying musn’t affect the other array.
 • You MUST use the operator new[] to allocate memory. Preventive allocation (al
locating memory in advance) is forbidden. Your program must never access non
allocated memory.
 • Elements can be accessed through the subscript operator: [ ].
 • When accessing an element with the [ ] operator, if its index is out of bounds, an
 std::exception is thrown.
 • Amember function size() that returns the number of elements in the array. This
 member function takes no parameters and must not modify the current instance.
 As usual, ensure everything works as expected and turn in a main.cpp file that con
tains your tests

*/

#endif