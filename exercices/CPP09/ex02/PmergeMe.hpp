#pragma once

#include <list>
#include <deque>
#include <iostream>
#include <iomanip>

class PmergeMe {
	private:
		PmergeMe ();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static std::list<int> mergeInsertionList(std::list<int>& bigList);
		static std::deque<int> mergeInsertionDeque(std::deque<int>& bigDeque);
		static void binaryInsertList(std::list<int>& mainChain, int value);
		static void binaryInsertDeque(std::deque<int>& mainChain, int value);

		template <typename Container>
		static void printContainerCompact(const Container &c,
										std::size_t head = 5, std::size_t tail = 5) {
			std::size_t n = c.size();
			std::size_t count = 0;

			for (auto it = c.begin(); it != c.end(); ++it, ++count) {
				if (count < head || count >= n - tail) {
					std::cout << *it;
					if (count != n - 1) std::cout << ' ';
				} else if (count == head) {
					std::cout << ".. ";
				}
			}
		}

	public:
		static std::list<int> sortList(const std::list<int>& input);
		static std::deque<int> sortDeque(const std::list<int>& input);

		template <typename first, typename second>
		static void printResult(const first& f, const second& s,
									double durationList, double durationDeque) {
			std::cout << "Before: ";
			printContainerCompact(f);
			std::cout << "\nAfter: ";
			printContainerCompact(s);
			std::cout << std::endl;
			std::cout << "Time to process a range of " << f.size()
					<< " elements with std::list  : " << std::fixed
					<< std::setprecision(4) << durationList << " us" << std::endl;
			std::cout << "Time to process a range of " << f.size()
					<< " elements with std::deque : " << std::fixed
					<< std::setprecision(4) << durationDeque << " us" << std::endl;
		}
};
