#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
	_name(name), _grade (grade) {

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name), _grade (other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::promoteBureaucrat() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::demoteBureaucrat() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << "\033[37m" << _name << " signed " << form.getName() << "\033[0m" << std::endl;
	}
	catch (const std::exception& e) {
		 std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	form.execute(*this);
	std::cout << "\033[37m" << getName() << " executed " << form.getName() <<"\033[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << "\033[37m" << bureaucrat.getName() << ", bureaucrat grade "
	<< bureaucrat.getGrade() << "\033[0m";
	return os;
}
