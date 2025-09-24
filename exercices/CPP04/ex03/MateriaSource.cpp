#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		std::cout << "MateriaSource assigment operator called" << std::endl;
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << "\033[31mLearnMateria called\033[0m" << std::endl;
			getGlobalManager().add(m);
			std::cout << "Learning " << m->getType() <<" materia at slot "<< i <<std::endl;
			return;
		}
	}
	getGlobalManager().add(m);
	std::cout << "Inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			return inventory[i]->clone();
		}
	}
	std::cout << "Creation of " << type <<" materia failed! Need to learn " << type << " materia" <<std::endl;
	return nullptr;
}
