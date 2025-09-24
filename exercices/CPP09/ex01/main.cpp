#include "RPN.hpp"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error usage: ./RPN 'RPN expression'" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	try {
		RPN rpn(input);
		// std::cout << "Copy constructor" << std::endl;
		// RPN rpnCopy(rpn);
		// std::cout << "Assignment constructor" << std::endl;
		// RPN rpnAssignment = rpn;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}