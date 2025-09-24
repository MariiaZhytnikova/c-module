#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw IsSignedException();
	std::cout << "\033[37m" << "* BZZZZZZ... VRRRRRR... BRRRRRR! *" << "\033[0m" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << getTarget() << "!" << std::endl;
}
