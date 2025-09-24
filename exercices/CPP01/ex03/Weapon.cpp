/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:42:34 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:55:41 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon:: Weapon(const std::string& type) : _type(type) {
	std::cout << "Weapon constructor is called" << std::endl;
}

Weapon:: ~Weapon() {
	std::cout << "Weapon destructor is called" << std::endl;
}

void Weapon::setType(const std::string& type) {
	std::cout << "Weapon changed to " << type << std::endl;
	_type = type;
}

const std::string& Weapon:: getType() const {
	return _type;
}
