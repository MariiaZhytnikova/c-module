#include "Character.hpp"

Character::Character() : _name("Doe") {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "Character " << name << " constructor called" << std::endl;
}

Character::Character(Character const& other) : _name(other._name) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		std::cout << "Character assigment operator called" << std::endl;
		_name = other._name;
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

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			std::cout << "Equipping " << m->getType() << " materia on slot " << i << std::endl;
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid inventory index" << std::endl;
		return;
	}
	if (inventory[idx]) {
		inventory[idx] = NULL;
		std::cout << "\033[37m" << "You freed " << idx << " slot" << "\033[0m" << std::endl;
		return;
	}
	else
		std::cout << "\033[37m" << "You try to free empty slot" << "\033[0m" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid slot index, we have only 4 slots" << std::endl;
		return;
	}
	if (inventory[idx])
		inventory[idx]->use(target);
}
