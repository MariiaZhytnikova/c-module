/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:42:26 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 11:52:43 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(const std::string& type);
		~Weapon();

	// Setters
	void setType(const std::string& type);

	// Getters
	const std::string& getType() const;
};

#endif