#include "Span.hpp"

Span::Span() : _data(nullptr), _size(0), _count(0) {}

Span::Span(size_t N) : _data(new int[N]), _size(N), _count(0) {
}

Span::Span(const Span& other)
	: _data(new int[other._size]), _size(other._size), _count(other._count)  {
	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

Span& Span::operator =(const Span& other) {
	if (this != &other) {
		delete [] _data;
		_size = other._size;
		_count = other._count;
		_data = new int[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

Span::~Span() {
	delete [] _data;
}

void Span::addNumber(int number) {
	if (_count == _size)
		throw std::out_of_range("addNumber: No empty space left");
	_data[_count++] = number;
}

size_t Span::getSize() const {
	return _size;
}

int Span::getValue(size_t index) const {
	if (index < _count)
		return _data[index];
	throw std::out_of_range("Out of range");
}

size_t Span::getCount() const {
		return _count;
}

size_t Span::shortestSpan() const {
	if (_count < 2)
		throw std::out_of_range("No span can be found");
	
	std::vector<int> values(_data, _data + _count);
	std::sort(values.begin(), values.end());

	size_t minSpan = std::numeric_limits<size_t>::max();
	for (size_t i = 1; i < values.size(); i++) {
		size_t diff = static_cast<size_t>(values[i] - values[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

size_t Span::longestSpan() const {
	if (_count < 2)
		throw std::out_of_range("No span can be found");

	std::vector<int> values(_data, _data + _count);
	std::sort(values.begin(), values.end());

	return static_cast<size_t>(values.back() - values.front());
}

std::ostream& operator<<(std::ostream& os, const Span& arr) {
	for (size_t i = 0; i < arr.getCount(); i++)
		os << arr.getValue(i) << " ";
	return os;
}