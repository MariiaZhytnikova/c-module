#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	try {
		std::vector<int>	v = {1, 2, 3, 4, 5};
		std::list<int>		l = {10, 20, 30, 40};

		auto it1 = easyfind(v, 3);
		std::cout << "Found in vector: " << *it1 << std::endl;

		auto it2 = easyfind(l, 20);
		std::cout << "Found in list: " << *it2 << std::endl;

		auto it3 = easyfind(v, 42);
		std::cout << "Found in vector: " << *it3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		const std::vector<int>	v = {1, 2, 3, 4, 5};
		const std::list<int>		l = {10, 20, 30, 40};

		auto it1 = easyfind(v, 3);
		std::cout << "Found in vector: " << *it1 << std::endl;

		auto it2 = easyfind(l, 20);
		std::cout << "Found in list: " << *it2 << std::endl;

		auto it3 = easyfind(v, 42);
		std::cout << "Found in vector: " << *it3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}