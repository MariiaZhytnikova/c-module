#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw IsSignedException();

	std::string	outFile = getTarget() + "_shrubbery";
	std::ofstream	outputFile(outFile);
	if (!outputFile) {
		std::cerr << "Error" << std::endl;
		std::cerr << outFile << " : failed to open file for writing." << std::endl;
		return;
	}
	outputFile << "   🌸🌸🌸        🌸🌸🌸        🌸🌸🌸     " << std::endl;
	outputFile << " 🌸🌳🌸🌳🌸    🌸🌳🌸🌳🌸    🌸🌳🌸🌳🌸   " << std::endl;
	outputFile << "🌳🌸🌳🌸🌳🌸  🌳🌸🌳🌸🌳🌸  🌳🌸🌳🌸🌳🌸  " << std::endl;
	outputFile << "  🌳🌸🌳🌸      🌳🌸🌳🌸      🌳🌸🌳🌸    " << std::endl;
	outputFile << "     🌸   🌸🌸🌸         🌸🌸🌸         🌸 " << std::endl;
	outputFile << " 🌸     🌸🌳🌸🌳🌸     🌸🌳🌸🌳🌸  🌸      " << std::endl;
	outputFile << "      🌳🌸🌳🌸🌳🌸   🌳🌸🌳🌸🌳🌸     🌸  " << std::endl;
	outputFile << "  🌸     🌳🌸🌳🌸       🌳🌸🌳🌸          " << std::endl;
	outputFile << "   🌸🌸🌸        🌸🌸🌸        🌸🌸🌸     " << std::endl;
	outputFile << " 🌸🌳🌸🌳🌸    🌸🌳🌸🌳🌸    🌸🌳🌸🌳🌸   " << std::endl;
	outputFile << "🌳🌸🌳🌸🌳🌸  🌳🌸🌳🌸🌳🌸  🌳🌸🌳🌸🌳🌸  " << std::endl;
	outputFile << "  🌳🌸🌳🌸      🌳🌸🌳🌸      🌳🌸🌳🌸    " << std::endl;
	outputFile.close();
}
