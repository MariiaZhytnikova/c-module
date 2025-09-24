#pragma once

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
	private:
		std::stack<int> _stack;
		RPN();

	public:
		RPN(std::string& input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
};