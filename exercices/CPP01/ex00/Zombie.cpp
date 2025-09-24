/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:37 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:37:08 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << _name << " constructor is called" << std::endl;
}
Zombie::~Zombie(){
	std::cout << "Zombie " << _name << " destructor is called" << std::endl;
}
void Zombie::announce() const {
	std::cout << _name << " >: BraiiiiiiinnnzzzZ..." << std::endl;
}
