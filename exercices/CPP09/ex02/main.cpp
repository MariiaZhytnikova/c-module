#include "PmergeMe.hpp"
#include <chrono>

int	main(int argc, char** argv) {

	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::list<int> numbers;

	for (int i = 1; i < argc; ++i) {
		try {
			size_t pos;
			std::string str = argv[i];
			int num = std::stoi(str, &pos);
			if (pos != str.size() || num < 0) {
				std::cerr << "Error: Invalid number: " << str << std::endl;
				return 1;
			}
			numbers.push_back(num);
		} catch (const std::exception& e) {
			std::cerr << "Error: Invalid number: " << argv[i] << std::endl;
			return 1;
		}
	}

	auto startList = std::chrono::high_resolution_clock::now();
	std::list<int> sortedList = PmergeMe::sortList(numbers);
	auto endList = std::chrono::high_resolution_clock::now();
	double durationList =
				std::chrono::duration<double, std::micro>(endList - startList).count();

	auto startDeque = std::chrono::high_resolution_clock::now();
	std::deque<int> sortedDeque = PmergeMe::sortDeque(numbers);
	auto endDeque = std::chrono::high_resolution_clock::now();
	double durationDeque =
				std::chrono::duration<double, std::micro>(endDeque - startDeque).count();

	PmergeMe::printResult(numbers, sortedList, durationList, durationDeque);

	return 0;
}


