#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++) {
		if (forms[i] == name)
			switch (i) {
				case 0: return new ShrubberyCreationForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new PresidentialPardonForm(target);
		}
	}
	std::cout << "Intern cannot create form: " << name << std::endl;
	return nullptr;
}