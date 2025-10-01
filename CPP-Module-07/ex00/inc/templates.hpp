/*
template <typename T>
T add(T a, T b) {
    return a + b;
}
*/

template <typename T>
void swap(T a, T b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename A>
A min(A a, A b) { return ((a < b) ? a : b); }

template <typename B>
B max(B a, B b) { return ((a > b) ? a : b); }
