#include "whatever.hpp"
#include <cassert>
#include <iostream>

int main() {

	int a = 5, b = 10;

	std::cout << "swap test: a = " << a << " b = " << b << std::endl;
	swap(a, b);
	assert(a == 10 && b == 5);

	std::cout << "min/max test" << std::endl;
	assert(min(a, b) == b); // b=2, a=3, so min is 2
	assert(max(a, b) == a); // a=3, b=2, so max is 3

	std::cout << "min/max string test" << std::endl;
	
	std::string s1 = "apple", s2 = "banana";

	swap(s1, s2);
	assert(s1 == "banana" && s2 == "apple");

	assert(::min(s1, s2) == "apple");
	assert(::max(s1, s2) == "banana");

	std::cout << "Passed XD" << std::endl;

	std::cout << "swap test before: a = " << a << " b = " << b << std::endl;
	swap(a, b);
	std::cout << "swap test after: a = " << a << " b = " << b << std::endl;

	std::cout << "swap test before: s1 = " << s1 << " s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "swap test before: s1 = " << s1 << " s2 = " << s2 << std::endl;

	std::cout << "min test: " << min(a, b) << std::endl;
	std::cout << "max test: " << max(a, b) << std::endl;

	std::cout << "min test: " << ::min(s1, s2) << std::endl;
	std::cout << "max test: " << ::max(s1, s2) << std::endl;

	return 0;
}