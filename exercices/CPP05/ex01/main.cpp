#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form f1("Sopimus", 1, 1);
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 1);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f2("Too high", 0, 1);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f3("Too high", 1, 0);
		std::cout << f3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f4("Too low", 151, 1);
		std::cout << f4 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form f5("Too low", 1, 151);
		std::cout << f5 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Jenny", 75);
		std::cout << b3 << std::endl;
		Form f1("Sopimus 75 to sign", 75, 1);
		std::cout << f1 << std::endl;
		b3.signForm(f1);
		std::cout << f1 << std::endl;
		Form f2("Sopimus 70 to sign", 70, 1);
		std::cout << f2 << std::endl;
		b3.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
