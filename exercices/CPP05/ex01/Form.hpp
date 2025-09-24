#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Grade is too high!";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Grade is too low!";
			}
		};

		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		
		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& Form);