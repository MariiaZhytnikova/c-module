#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	std::cout << "\033[33m" << "\n Learn new materia" << "\033[0m" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\033[33m" << "\n Character creation" << "\033[0m" << std::endl;
	ICharacter* me = new Character("me");

	std::cout << "\033[33m" << "\n Materia creation and equip" << "\033[0m" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\033[33m" << "\n New target character creation" << "\033[0m" << std::endl;
	ICharacter* bob = new Character("bob");
	
	std::cout << "\033[33m" << "\n Use of Materia on target" << "\033[0m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\033[33m" << "\n Now we will learn more Materia" << "\033[0m" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	me->unequip(2);

	std::cout << "\033[33m" << "\n And equip more Materia" << "\033[0m" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << "\033[33m" << "\n And use everything we have and even more" << "\033[0m" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-4, *bob);

	std::cout << "\033[33m" << "\n Time to drop something" << "\033[0m" << std::endl;

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	return 0;
}
