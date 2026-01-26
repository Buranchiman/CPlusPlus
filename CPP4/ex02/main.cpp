#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animalTab[10];
	std::cout << "\033[37mTesting for array" << std::endl;
	for(int i = 0; i < 10; i ++)
	{
		std::cout << "\033[37m----------------------------------------\nCreating elem[" << i << "] of tab" << std::endl;
		if (i < 5)
			animalTab[i] = new Dog();
		else
			animalTab[i] = new Cat();
	}
	for(int j = 0; j < 10; j ++)
	{
		std::cout << "\033[37m----------------------------------------\nDeleting elem[" << j << "] of tab :" << std::endl;
		delete (animalTab[j]);
	}
	std::cout << "\033[37m----------------------------------------\nTesting deep copies" << std::endl;
	Dog test;
	test.fillBrain("bones");
	test.showsIdea();
	Dog copy(test);
	copy.showsIdea();
	Cat test2;
	test2.fillBrain("fishes");
	test2.showsIdea();
	Cat copy2(test2);
	copy2.showsIdea();
	std::cout << "\033[37m----------------------------------------\nDestructors:" << std::endl;
	return (0);
}
