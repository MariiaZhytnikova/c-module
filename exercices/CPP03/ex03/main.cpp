/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:47 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/14 11:35:46 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(){
	DiamondTrap test("Me");
	FragTrap first("BoB");

	std::cout << std::endl;
	test.attack("BoB");
	first.takeDamage(30);
	std::cout << std::endl;
	test.whoAmI();
}
