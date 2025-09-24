#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void printPseudo(const std::string& input) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (input == "nan" || input == "nanf")
		std::cout << "float: nanf\n";
	else if (input == "+inf" || input == "+inff")
		std::cout << "float: +inff\n";
	else
		std::cout << "float: -inff\n";

	if (input == "nan" || input == "nanf")
		std::cout << "double: nan\n";
	else if (input == "+inf" || input == "+inff")
		std::cout << "double: +inf\n";
	else
		std::cout << "double: -inf\n";
}

Type detectType(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0])) {
		return CHAR;
	}

	if (!input.find('.')) {
		try {
			std::stoi(input);
			return INT;
		} catch (const std::exception& e) {}
	}

	if (input.back() == 'f') {
		try {
			std::stof(input);
			return FLOAT;
		} catch (const std::exception& e) {}
	}

	try {
		std::stod(input);
		return DOUBLE;
	} catch (const std::exception& e) {}
	return INVALID;
}

void fromChar(const std::string& input) {
	char c = input[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void fromInt(const std::string& input) {
	int i = std::stoi(input);
	if (i >= 32 && i <= 126) {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void fromFloat(const std::string& input) {
	float f = std::stof(input);

	if (f >= 32 && f <= 126 && std::floor(f) == f) {
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	if (f >= static_cast<float>(std::numeric_limits<int>::min()) &&
			f <= static_cast<float>(std::numeric_limits<int>::max())) {
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	if (std::isinf(f))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "
			<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: "
		<< std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void fromDouble(const std::string& input) {
	double d = std::stod(input);

	if (d >= 32 && d <= 126) {
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	float f = static_cast<float>(d);
	if (std::isinf(f))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: "
			<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: "
		<< std::fixed << std::setprecision(1) << d << std::endl;
}

void fromInvalid(const std::string& input) {
	(void)input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string& input) {

	if (input == "nan" || input == "nanf" ||
		input == "+inf" || input == "+inff" ||
		input == "-inf" || input == "-inff") {
		printPseudo(input);
		return;
}

	Type type = detectType(input);

	void (*funcs[5])(const std::string&) = {
		fromChar,
		fromInt,
		fromFloat,
		fromDouble,
		fromInvalid
	};
	funcs[type](input);
}