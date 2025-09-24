/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:29 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/07/16 09:43:31 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	Zombie* horde = zombieHorde(10, "Boo");
	if (!horde) {
		std::cerr << "Something goes wrong!" << std::endl;
		return 1;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << i << " > ";
		horde[i].announce();
		}
	delete[] horde;
	return 0;
}