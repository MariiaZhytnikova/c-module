/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:43:47 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:32:48 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){
	Zombie* hZombie = newZombie("Foo");
	hZombie->announce();
	Zombie* dZombie = newZombie("Doo");
	dZombie->announce();
	Zombie* mZombie = newZombie("Moo");
	mZombie->announce();
	delete hZombie;
	delete dZombie;
	delete mZombie;

	randomChump("Boo");
	randomChump("Loo");
	randomChump("Soo");
	randomChump("Xoo");
}