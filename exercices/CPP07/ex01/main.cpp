#include "iter.hpp"
#include <iostream>

template <typename T>
void printAnything(T& x) {
	std::cout << x << " ";
}

template <typename T>
void doubleValue(T& x) {
	x = x * 2;
}

void toUpper(std::string& s) {
	for (size_t i = 0; i < s.size(); i++)
		s[i] = std::toupper(s[i]);
}


int main () {
	int nums[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::string words[9] = {"Nine", "eight", "seVen", "sIx", "FivE", "four", "three", "twO", "OnE"};
	double reals[9] = {9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};

	std::cout << "int nums[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1} double" << std::endl;
	iter(nums, 9, printAnything<int>);
	std::cout << std::endl;
	iter(nums, 9, doubleValue<int>);
	iter(nums, 9, printAnything<int>);
	std::cout << "\n" << std::endl;

	std::cout << "std::string words[9] = {\"9\", \"8\", \"7\", \"6\", \"5\", \"4\", \"3\", \"2\", \"1\"} to upper" << std::endl;
	iter(words, 9, printAnything<std::string>);
	std::cout << std::endl;
	iter(words, 9, toUpper);
	iter(words, 9, printAnything<std::string>);
	std::cout << "\n" << std::endl;

	std::cout << "reals[9] = {9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1} double" << std::endl;
	iter(reals, 9, printAnything<double>);
	std::cout << std::endl;
	iter(reals, 9, doubleValue<double>);
	iter(reals, 9, printAnything<double>);
	std::cout << std::endl;
}