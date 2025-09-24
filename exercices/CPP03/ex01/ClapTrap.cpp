#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _name(name) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy operator called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		std::cout << "ClapTrap assigment operator called" << std::endl;
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target
				<< " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points to attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " can't attack, it's dead...!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0) {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount
				<< " points of damage! " << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't take damage, it's dead...!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself and gets " << amount
			  << " hit points back now: " << _hitPoints << "!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " has no energy points to repair!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " can't repair itself, it's dead...!" << std::endl;
}
