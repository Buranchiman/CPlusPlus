#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog			  dog;
	Cat			  cat;
	const WrongAnimal* wrong = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	cat.makeSound();
	j->makeSound();
	dog.makeSound();
	meta->makeSound();
	wrong->makeSound();
	delete(i);
	delete(j);
	delete(meta);
	delete(wrong);
	return (0);
}
