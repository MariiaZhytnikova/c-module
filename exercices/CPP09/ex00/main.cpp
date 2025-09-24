#include "BitcoinExchange.hpp"
#include <fstream>

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string		filename = argv[1];

	std::ifstream	inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}

	std::ifstream	dataFile("data.csv");
	if (!dataFile.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		inputFile.close();
		return (false);
	}

	BitcoinExchange exchange(dataFile, inputFile);
	exchange.Exchange();

	inputFile.close();
	dataFile.close();
/*
	std::cout << "\nCheck assigment and copy operators" << std::endl;
	BitcoinExchange exchangeCopy(exchange);
	BitcoinExchange exchangeAssignment = exchange;

	std::cout << "Print copy" << std::endl;
	std::cout << exchangeCopy.getInput() << std::endl;
	std::cout << "Print assigment" << std::endl;
	std::cout << exchangeAssignment.getInput() << std::endl;

	std::cout << "\nExchange of assigment and copy\n" << std::endl;
	exchangeCopy.Exchange();
	std::cout << std::endl;
	exchangeAssignment.Exchange();
*/
	return 0;
}