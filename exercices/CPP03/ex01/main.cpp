/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:47 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/14 11:25:26 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(){
	ScavTrap first("BoB");
	ScavTrap second("SeM");
	ScavTrap third("Joe");
	

	std::cout << std::endl;
	first.attack("SeM");
	second.takeDamage(20);
	first.attack("SeM");
	second.takeDamage(20);
	first.attack("SeM");
	second.takeDamage(20);
	first.attack("SeM");
	second.takeDamage(20);
	first.attack("SeM");
	second.takeDamage(20);
	std::cout << std::endl;
	second.attack("Joe");
	second.beRepaired(50);
	std::cout << std::endl;
	first.attack("Joe");
	third.takeDamage(20);
	std::cout << std::endl;
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(5);
	first.beRepaired(5);
	std::cout << std::endl;

	first.guardGate();
	second.guardGate();
	third.guardGate();
	std::cout << std::endl;
}