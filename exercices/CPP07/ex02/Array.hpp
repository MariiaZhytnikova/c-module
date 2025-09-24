#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T*		_data;
		size_t	_size;

	public:
		Array();
		Array(size_t N);
		Array(const Array& other);
		Array<T>& operator=(const Array& other);
		~Array();

		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

#include "Array.tpp"
