#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
	private:
		int*	_data;
		size_t	_size;
		size_t	_count;

	public:
		Span();
		Span(size_t N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

	void	addNumber(int number);
	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end);
	size_t	getSize() const;
	int		getValue(size_t index) const;
	size_t	getCount() const;
	size_t	shortestSpan() const;
	size_t	longestSpan() const;
};

#include "Span.tpp"

std::ostream& operator<<(std::ostream& os, const Span& arr);
