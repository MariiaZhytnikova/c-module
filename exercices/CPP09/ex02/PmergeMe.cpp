#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

std::list<int> PmergeMe::sortList(const std::list<int>& input) {

	std::list<int> bigList;
	std::list<int> smallList;

	auto it = input.begin();
	while (it != input.end()) {
		int first = *it;
		++it;
		if (it == input.end()) {
			bigList.push_back(first);
			break;
		}
		int second = *it;
		++it;
		bigList.push_back(std::max(first, second));
		smallList.push_back(std::min(first, second));
	}
	bigList = mergeInsertionList(bigList);

	for (int small : smallList) {
		binaryInsertList(bigList, small);
	}

	return bigList;
}

std::deque<int> PmergeMe::sortDeque(const std::list<int>& input) {
	std::deque<int> bigDeque;
	std::deque<int> smallDeque;

	auto it = input.begin();
	while (it != input.end()) {
		int first = *it;
		++it;
		if (it == input.end()) {
			bigDeque.push_back(first);
			break;
		}
		int second = *it;
		++it;
		bigDeque.push_back(std::max(first, second));
		smallDeque.push_back(std::min(first, second));
	}
	bigDeque = mergeInsertionDeque(bigDeque);
	for (int small : smallDeque) {
		binaryInsertDeque(bigDeque, small);
	}

	return bigDeque;
}

std::list<int> PmergeMe::mergeInsertionList(std::list<int>& bigList) {
	if (bigList.size() < 2)
		return bigList;
	else if (bigList.size() == 2) {
		auto it = bigList.begin();
		int a = *it++;
		int b = *it;
		return { std::min(a, b), std::max(a, b) };
	}

	std::list<int> big;
	std::list<int> small;
	auto it = bigList.begin();

	while (it != bigList.end()) {
		int first = *it;
		++it;
		if (it == bigList.end()) {
			big.push_back(first);
			break;
		}
		int second = *it;
		++it;
		big.push_back(std::max(first, second));
		small.push_back(std::min(first, second));
	}
	big = mergeInsertionList(big);

	for (int s : small) {
		binaryInsertList(big, s);
	}
	return big;
}

void PmergeMe::binaryInsertList(std::list<int>& chain, int value) {
	if (chain.empty()) {
		chain.push_back(value);
		return;
	}

	auto first = chain.begin();
	auto last  = chain.end();

	while (first != last) {
		auto mid = first;
		std::advance(mid, std::distance(first, last) / 2);

		if (value < *mid)
			last = mid;
		else
			first = std::next(mid);
	}
	chain.insert(first, value);
}

std::deque<int> PmergeMe::mergeInsertionDeque(std::deque<int>& bigDeque) {
	if (bigDeque.size() < 2)
		return bigDeque;
	else if (bigDeque.size() == 2) {
		auto it = bigDeque.begin();
		int a = *it++;
		int b = *it;
		return { std::min(a, b), std::max(a, b) };
	}

	std::deque<int> big;
	std::deque<int> small;
	auto it = bigDeque.begin();

	while (it != bigDeque.end()) {
		int first = *it;
		++it;
		if (it == bigDeque.end()) {
			big.push_back(first);
			break;
		}
		int second = *it;
		++it;
		big.push_back(std::max(first, second));
		small.push_back(std::min(first, second));
	}
	big = mergeInsertionDeque(big);

	for (int s : small) {
		binaryInsertDeque(big, s);
	}
	return big;
}

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, int value) {
	if (mainChain.empty()) {
		mainChain.push_back(value);
		return;
	}

	int left = 0;
	int right = mainChain.size();

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (value < mainChain[mid])
			right = mid;
		else
			left = mid + 1;
	}
	mainChain.insert(mainChain.begin() + left, value);
}

