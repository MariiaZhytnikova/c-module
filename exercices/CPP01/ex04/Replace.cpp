/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:03:49 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/08/12 12:03:51 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>

bool replaceAll(std::string& line, const std::string& s1, const std::string& s2) {

	size_t	pos = 0;
	bool	replaced = false;

	if (s1.empty())
		return (replaced);

	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos += s2.size();
		replaced = true;
	}

	return (replaced);
}

bool Replace(const std::string& filename, const std::string& s1, const std::string& s2) {

	if (filename.empty()) {
		std::cerr << "Error" << std::endl;
		std::cerr << "Filename is empty, cannot open file." << std::endl;
		return (false);
	}

	std::ifstream	inputFile(filename);

	if (!inputFile.is_open()) {
		std::cerr << "Error" << std::endl;
		std::cerr << filename << " : failed to open file for reading." << std::endl;
		return (false);
	}

	std::string		outFile = filename + ".replace";
	std::ofstream	outputFile(outFile);

	if (!outputFile) {
		std::cerr << "Error" << std::endl;
		std::cerr << outFile << " : failed to open file for writing." << std::endl;
		return (false);
	}

	std::string		line;
	bool			current = false;
	bool			replaced = false;

	while (std::getline(inputFile, line)) {
		current = replaceAll(line, s1, s2);
		if (current)
			replaced = current;
		outputFile << line << std::endl;
	}

	outputFile.close();
	inputFile.close();

	if (replaced)
		std::cout << "\"" << s1 << "\" was replaced with \"" << s2 << "\" and saved to " << outFile << std::endl;
	else
		std::cout << "No string to replace was found " << std::endl;
	return (true);
}
