#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animalTab[10];
	std::cout << "Testing for array" << std::endl;
	for(int i = 0; i < 10; i ++)
	{
		std::cout << "----------------------------------------\nCreating elem[" << i << "] of tab" << std::endl;
		if (i < 5)
			animalTab[i] = new Dog();
		else
			animalTab[i] = new Cat();
	}
	for(int j = 0; j < 10; j ++)
	{
		std::cout << "----------------------------------------\nDeleting elem[" << j << "] of tab :" << std::endl;
		delete (animalTab[j]);
	}
	std::cout << "----------------------------------------\nTesting deep copies" << std::endl;
	Dog test;
	test.fillBrain("bones");
	test.showsIdea();
	Dog copy(test);
	copy.showsIdea();
	Cat test2;
	test2.fillBrain("fishes");
	test2.showsIdea();
	Dog copy2(test);
	copy2.showsIdea();
	std::cout << "----------------------------------------\nDestructors:" << std::endl;
	return (0);
}
