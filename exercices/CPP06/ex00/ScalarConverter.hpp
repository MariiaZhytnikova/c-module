#pragma once

#include <string>
#include <iostream>

enum Type {CHAR, INT, FLOAT, DOUBLE, INVALID};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter(); 
	public:
		static void convert(const std::string& input);
};
