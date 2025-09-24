#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw IsSignedException();
	std::cout << "\033[37m" << getTarget() << " has been pardoned by Zaphod Beeblebrox" << "\033[0m" << std::endl;
}
