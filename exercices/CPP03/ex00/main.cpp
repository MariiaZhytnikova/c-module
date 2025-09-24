/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:47 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/14 11:23:00 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap first("BoB");
	ClapTrap second("SeM");
	ClapTrap third("Joe");

	std::cout << std::endl;
	first.attack("SeM");
	second.takeDamage(15);
	std::cout << std::endl;
	second.attack("Joe");
	second.beRepaired(2);
	first.attack("SeM");
	second.takeDamage(1);
	std::cout << std::endl;
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	third.takeDamage(1);
	first.attack("Joe");
	std::cout << std::endl;
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(3);
	third.beRepaired(5);
	first.beRepaired(5);
	std::cout << std::endl;
}