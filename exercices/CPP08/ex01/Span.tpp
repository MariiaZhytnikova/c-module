#pragma once

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	if (std::distance(begin, end) > static_cast<long>(_size - _count))
		throw std::out_of_range("addNumbers: Not enough space for all numbers");
	for (Iterator it = begin; it != end; ++it) {
		addNumber(*it);
	}
}