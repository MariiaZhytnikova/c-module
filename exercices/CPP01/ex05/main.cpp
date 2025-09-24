/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:09:43 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 12:09:45 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {

	Harl harl;

	std::cout << "Testing DEBUG: " << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl;

	std::cout << "Testing INFO: " << std::endl;
	harl.complain("INFO");

	std::cout << std::endl;

	std::cout << "Testing WARNING: " << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl;

	std::cout << "Testing ERROR: " << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl;

	std::cout << "Testing TEST: " << std::endl;
	harl.complain("TEST");

	return (0);
}