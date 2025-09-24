#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : 
	_name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute){
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

bool Form::isSigned() const {
	return _signed;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "\033[37m" << form.getName()
	<< " form: grade to sign " << form.getGradeToSign()
	<< ", grade to execute " << form.getGradeToExecute()
	<< ", signed: " << form.isSigned() << "\033[0m";
	return os;
}
