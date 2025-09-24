/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:42:24 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:52:37 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanB(const std::string& name, Weapon* weapon = nullptr);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& weapon);
};

#endif