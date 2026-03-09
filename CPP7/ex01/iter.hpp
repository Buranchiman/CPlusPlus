#ifndef iter_HPP
#define iter_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, const std::size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T, typename F>
void iter(const T* array, const std::size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void display(const T& show)
{
	std::cout << show << ", ";
}

#endif
