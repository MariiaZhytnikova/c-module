/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:47 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/14 11:34:33 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){
	ClapTrap a("Bro");
	ScavTrap b("Sis");
	FragTrap first("BoB");
	FragTrap second("SeM");
	FragTrap third("Joe");

	std::cout << std::endl;
	a.attack("Bro");
	b.takeDamage(0);
	b.attack("Sis");
	a.takeDamage(20);
	b.guardGate();
	std::cout << std::endl;
	first.attack("SeM");
	second.takeDamage(30);
	first.attack("SeM");
	second.takeDamage(30);
	first.attack("SeM");
	second.takeDamage(30);
	first.attack("SeM");
	second.takeDamage(30);
	first.attack("SeM");
	second.takeDamage(30);
	std::cout << std::endl;
	second.attack("Joe");
	second.beRepaired(30);
	std::cout << std::endl;
	first.attack("Joe");
	third.takeDamage(30);
	std::cout << std::endl;
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(5);
	first.beRepaired(5);
	std::cout << std::endl;

	first.highFivesGuys();
	second.highFivesGuys();
	third.highFivesGuys();
	std::cout << std::endl;
}