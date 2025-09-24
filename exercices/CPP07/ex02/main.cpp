#include "Array.hpp"
#include <string>

int main() {
	Array<int> a;
	Array<double> b(5);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		Array<int> c(9);
		for (size_t i = 0; i < 9; i++)
			c[i] = i;
		std::cout << c << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	try {
		Array<double> d(9);
		for (size_t k = 1; k < 10; k++)
			d[k - 1] = 0.1 * k + k;
		std::cout << d << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	try {
		Array<std::string> e(9);
		std::string words[9] = {"Nine", "eight", "seVen", "sIx", "FivE", "four", "three", "twO", "OnE"};
		for (size_t l = 0; l < 9; l++)
			e[l] = words[l];
		std::cout << e << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	try {
		Array<double> d(9);
		for (size_t k = 1; k < 10; k++)
			d[k] = 0.1 * k + k;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
}