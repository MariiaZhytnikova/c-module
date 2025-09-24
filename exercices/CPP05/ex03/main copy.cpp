#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

int main() {
	std::srand(std::time(nullptr));
	try {
		ShrubberyCreationForm f1("Cherry Garden", "Cherry");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 1);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		RobotomyRequestForm f1("Need to fix", "Table");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 1);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
		b1.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm f1("New secretary", "Smith");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 1);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm f1("New secretary", "Smith");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 150);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm f1("New secretary", "Smith");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 25);
		Bureaucrat b2("John", 4);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm f1("New secretary", "Smith");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 4);
		Bureaucrat b2("John", 26);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		PresidentialPardonForm f1("New secretary", "Smith");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 150);
		Bureaucrat b2("John", 150);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		ShrubberyCreationForm f1("Garden v2", "Cherry");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 4);
		Bureaucrat b2("John", 26);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		RobotomyRequestForm f1("Need to fix","Chair");
		std::cout << f1 << std::endl;
		Bureaucrat b1("Joe", 4);
		Bureaucrat b2("John", 26);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.executeForm(f1);
		b1.executeForm(f1);
		b2.executeForm(f1);
		b1.executeForm(f1);
		b2.executeForm(f1);
		b1.executeForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
