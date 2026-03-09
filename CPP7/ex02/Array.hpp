#ifndef Array_HPP
#define Array_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T 				*_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int size() const;
	T& operator[](int index);
	const T& operator[](int index) const;
};

#include "Array.tpp"

#endif
