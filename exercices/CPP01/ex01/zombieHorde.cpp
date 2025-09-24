/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:15 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/07/16 09:43:17 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return nullptr;
	Zombie *horde = new Zombie[N];
	for (int i = 0; i< N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
