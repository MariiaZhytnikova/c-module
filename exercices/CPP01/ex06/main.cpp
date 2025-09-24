/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:10:32 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 12:14:34 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char** argv) {

	Harl harl;

	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <COMPLAIN>" << std::endl;
		return (1);
	}

	std::cout << "Testing HarlFilter: " << std::endl;

	std::string	complain = argv[1];
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			levelIndex = -1;
	int			i = 0;

	while (i < 4) {
		if (levels[i] == complain) {
			levelIndex = i;
			break;
		}
		i++;
	}
	std::cout << "[ " << complain << " ]\n";
	harl.harlFilter(levelIndex);

	return (0);
}