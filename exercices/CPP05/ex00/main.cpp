#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("Joe", 1);

		std::cout << b1 << std::endl;
		std::cout << "\033[31mIncrement Joe\033[0m" << std::endl;
		b1.promoteBureaucrat();
		std::cout << b1 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Sam", 25);

		std::cout << b2 << std::endl;
		std::cout << "\033[31mIncrement Sam\033[0m" << std::endl;
		b2.promoteBureaucrat();
		std::cout << b2 << std::endl;
		std::cout << "\033[31mDecrement Sam\033[0m" << std::endl;
		b2.demoteBureaucrat();
		std::cout << b2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Jenny", 75);

		std::cout << b3 << std::endl;
		std::cout << "\033[31mIncrement Jenny\033[0m" << std::endl;
		b3.promoteBureaucrat();
		std::cout << b3 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Samanta", 150);

		std::cout << b4 << std::endl;
		std::cout << "\033[31mIncrement Samanta\033[0m" << std::endl;
		b4.promoteBureaucrat();
		std::cout << b4 << std::endl;
		std::cout << "\033[31mDecrement Samanta\033[0m" << std::endl;
		b4.demoteBureaucrat();
		std::cout << b4 << std::endl;
		b4.demoteBureaucrat();
		std::cout << b4 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\033[31mLets create Bureaucrat with grade 0\033[0m" << std::endl;
		Bureaucrat b5("Too High", 0);

		std::cout << b5 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\033[31mLets create Bureaucrat with grade 200\033[0m" << std::endl;
		Bureaucrat b6("Too Low", 200);
		std::cout << b6 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}
