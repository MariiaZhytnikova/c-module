#include "RPN.hpp"

RPN::RPN(const RPN& other) : _stack(other._stack) {
	std::cout << _stack.top() << std::endl;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
		std::cout << _stack.top() << std::endl;
	}
	return *this;
}

RPN::~RPN() {}

bool	isNumber(const std::string inp) {
	if (inp.length() > 2 && (inp[0] == '-' || inp[0] == '+'))
		try {
			size_t pos = 0;
			std::stoi(inp.substr(1), &pos);
			if (pos != inp.size())
				return false;
			return true;
		}
		catch(const std::exception& e) {
			return false;
		}
	try {
			size_t pos;
			std::stoi(inp, &pos);
			if (pos != inp.size())
				return false;
			return true;
	}
	catch(const std::exception& e) {
		return false;
	}
}

bool	isOperator(const std::string inp) {
	return (inp.length() == 1 && (inp == "+" || inp == "-" || inp == "/" || inp == "*"));
}

int		applyOperator(int left, int right, char op) {
	int result;
	switch (op) {
		case '+':
			return result = left + right;
		case '-':
			return result = left - right;
		case '*':
			return result = left * right;
		case '/':
			if (right != 0)
				return result = left / right;
			throw std::runtime_error("Invalid RPN: Why you try divide by zero?? 😠😠😠");
		default:
			throw std::runtime_error("Invalid RPN: This should never happen");
	}
}

RPN::RPN(std::string& input) {
	std::istringstream iss(input);
	std::string token;

	while (iss >> token) {
		if (isNumber(token))
			_stack.push(std::stod(token));
		else if (isOperator(token)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Invalid RPN: not enough operands");
			int right = _stack.top();
			_stack.pop();
			int left  = _stack.top();
			_stack.pop();
			int result = applyOperator(left, right, token[0]);
			_stack.push(result);
		}
		else
			throw std::runtime_error("Invalid RPN: unknown token");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid RPN: Invalid number of operands");
	std::cout << _stack.top() << std::endl;
}