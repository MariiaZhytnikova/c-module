#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
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

		class IsSignedException : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Form should be signed before execution!";
			}
		};

		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		
		void beSigned(const Bureaucrat& bureaucrat);

		virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);