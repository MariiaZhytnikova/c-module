#include "Span.hpp"

int main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nAddNumbers test not enough space" << std::endl;
	std::vector<int> num = {1, 2, 3, 4, 5, 6, 7};

	try { sp.addNumber(11); }
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	try {
		Span	spBadVector = Span(5);
		spBadVector.addNumbers(num.begin(), num.end());
		std::cout << spBadVector << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	std::cout << "\nAddNumbers test correct size" << std::endl;
	try {
		Span	spVector = Span(7);
		spVector.addNumbers(num.begin(), num.end());
		std::cout << spVector << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	std::cout << "\n10 000 test" << std::endl;
	const size_t SIZE = 10000;

	std::vector<int> nums(SIZE);
	for (size_t i = 0; i < SIZE; i++)
		nums[i] = rand() % 100000;

	try {
		Span	spBig(SIZE);
		spBig.addNumbers(nums.begin(), nums.end());
		//std::cout << spBig << std::endl;
		std::cout << "Shortest span: " << spBig.shortestSpan() << std::endl;
		std::cout << "Longest span: " << spBig.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}