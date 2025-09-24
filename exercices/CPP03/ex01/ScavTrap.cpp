#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy operator called" << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
		if (this != &other) {
			std::cout << "ScavTrap assigment operator called" << std::endl;
			ClapTrap::operator=(other);
		}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target
				<< " causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap " << _name << " has no energy points to attack!" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " can't attack, it's dead...!" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (_hitPoints > 0)
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " can't be in Gate keeper mode, it's dead...!" << std::endl;
}
