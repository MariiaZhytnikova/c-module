/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:42:32 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:55:14 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA:: HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << "HumanA constructor is called" << std::endl;
}

HumanA:: ~HumanA() {
	std::cout << "HumanA destructor is called" << std::endl;
}

void HumanA:: attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
