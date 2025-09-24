#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

int main() {
	Intern noNameIntern;

	AForm* f1 = noNameIntern.makeForm("ShrubberyCreationForm", "Mustikka");
	AForm* f2 = noNameIntern.makeForm("RobotomyRequestForm", "Mustikka");
	AForm* f3 = noNameIntern.makeForm("PresidentialPardonForm", "Mustikka");

	std::srand(std::time(nullptr));
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	std::cout << std::endl;
	try {
		Bureaucrat b1("Joe", 55);
		std::cout << b1 << std::endl;
		b1.signForm(*f1);
		std::cout << *f1 << std::endl;
		b1.executeForm(*f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat b1("Joe", 55);
		std::cout << b1 << std::endl;
		b1.signForm(*f2);
		std::cout << *f2 << std::endl;
		b1.executeForm(*f2);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat b1("Joe", 55);
		std::cout << b1 << std::endl;
		b1.signForm(*f3);
		std::cout << *f3 << std::endl;
		b1.executeForm(*f3);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	delete f1;
	delete f2;
	delete f3;
}
