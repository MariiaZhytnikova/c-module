/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:48:48 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie constructor is called" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Zombie destructor is called" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::announce() const {
	std::cout << _name << " >: BraiiiiiiinnnzzzZ..." << std::endl;
}
