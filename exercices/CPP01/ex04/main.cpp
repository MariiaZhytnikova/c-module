/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:41 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 12:03:43 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char** argv) {

	if (argc != 4) {
		std::cerr << "Error" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];

	if (!Replace(filename, s1, s2)) {
		std::cerr << "An error occurred.\n";
		return (1);
	}

	return (0);
}
