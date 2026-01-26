#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colors.hpp"

int main()
{
	std::cout << BOLDMAGENTA << "Starting subjects tests ------------------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "Finished subjects tests ------------------------------" << std::endl;
	std::cout << BOLDRED << "Starting copy tests ------------------------------" << std::endl;
	Character* cpyPtr = NULL;
	{
		Character origin("origin");
		origin.equip(src->createMateria("ice"));
		origin.equip(src->createMateria("cure"));
		cpyPtr = new Character(origin);
	}
	cpyPtr->use(0, *bob);
	cpyPtr->use(1, *bob);
	std::cout << "finishing copy tests ------------------------------" << std::endl;
	std::cout << BOLDGREEN << "Starting unequip tests ------------------------------" << std::endl;
	AMateria *floor[2];
	Character *airHead = new Character("airHead");
	floor[0] = src->createMateria("ice");
	floor[1] = src->createMateria("cure");
	airHead->equip(floor[0]);
	airHead->equip(floor[1]);
	airHead->use(0, *bob);
	airHead->use(1, *bob);
	airHead->unequip(0);
	airHead->unequip(1);
	delete(floor[0]);
	delete(floor[1]);
	std::cout  << "Finishing unequip tests ------------------------------" << WHITE << std::endl;
	delete airHead;
	delete cpyPtr;
	delete bob;
	delete me;
	delete src;
	return 0;
}
