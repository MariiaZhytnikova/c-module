#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
};

#endif
