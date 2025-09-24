/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:42:53 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:55:26 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB:: HumanB(const std::string& name, Weapon* weapon) : _name(name), _weapon(weapon) {
	std::cout << "HumanB constructor is called" << std::endl;
}

HumanB:: ~HumanB() {
	std::cout << "HumanB destructor is called" << std::endl;
}

void HumanB:: setWeapon(Weapon& weapon){
	_weapon = &weapon;
}

void HumanB:: attack() const {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon!" << std::endl;
}
