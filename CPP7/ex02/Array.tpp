#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (_array)
			delete _array;
		this = other;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= (int)_size)
		throw(std::out_of_range("cannot acces index, it is out of bounds !"));
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || index >= (int)_size)
		throw(std::out_of_range("cannot acces index, it is out of bounds !"));
	return _array[index];
}
