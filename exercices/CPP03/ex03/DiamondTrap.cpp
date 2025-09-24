#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"),
			FragTrap(name), ScavTrap(name), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	std::cout << "DiamondTrap copy operator called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
			std::cout << "DiamondTrap assigment operator called" << std::endl;
			ClapTrap::operator=(other);
		}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << _name
			<< " and ClapTrap name is " << ClapTrap::_name << std::endl;
}
