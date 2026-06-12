#include "iter.hpp"

void	strawberry(const char *fruit)
{
	fruit = "strawberry";
}

void add_one(int& x)
{
	x++;
}

void add_copy(int x)
{
	x++;
}

void shout(std::string& s)
{
	s += "!";
}

int	main(void)
{
	int numbers[] = {1, 2, 3, 4};
	const int const_numbers[] = {10, 20, 30, 40};
	std::string words[] = {"hello", "world"};
	const std::string const_words[] = {"alpha", "beta"};
	const char* cwords[] = {"one", "two", "three"};

	std::cout << "numbers: ";
	iter(numbers, 4, display<int>);
	std::cout << std::endl;

	iter(numbers, 4, add_one);
	std::cout << "numbers after add_one: ";
	iter(numbers, 4, display<int>);
	std::cout << std::endl;

	iter(numbers, 4, add_copy);
	std::cout << "numbers after add_copy: ";
	iter(numbers, 4, display<int>);
	std::cout << std::endl;

	std::cout << "const_numbers: ";
	iter(const_numbers, 4, display<int>);
	std::cout << std::endl;

	std::cout << "words :";
	iter(words, 2, display<std::string>);
	std::cout << std::endl;
	iter(words, 2, shout);
	std::cout << "words after shout: ";
	iter(words, 2, display<std::string>);
	std::cout << std::endl;

	std::cout << "const_words: ";
	iter(const_words, 2, display<std::string>);
	std::cout << std::endl;

	std::cout << "cwords: ";
	iter(cwords, 3, display<const char*>);
	std::cout << std::endl;
}
