#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy operator called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
		if (this != &other) {
			std::cout << "FragTrap assigment operator called" << std::endl;
			ClapTrap::operator=(other);
		}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints > 0)
		std::cout << "FragTrap " << _name << ": You've got this! High five!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " can't do high fives request, it's dead...!" << std::endl;
}
