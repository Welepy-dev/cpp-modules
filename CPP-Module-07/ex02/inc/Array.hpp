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

		unsigned size(void) const;

	private:
		T			_array;
		unsigned	_size;
}


#endif