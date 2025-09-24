#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : 
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : 
	_name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute){
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

bool AForm::isSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {

	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
	os << "\033[37m" << aform.getName()
	<< " form: grade to sign " << aform.getGradeToSign()
	<< ", grade to execute " << aform.getGradeToExecute()
	<< ", signed: " << aform.isSigned() << "\033[0m";
	return os;
}
