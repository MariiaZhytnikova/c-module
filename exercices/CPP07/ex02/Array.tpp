#pragma once

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(size_t N) : _data(new T[N]()), _size(N) {}

template <typename T>
Array<T>::Array(const Array& other)
	: _data(new T[other._size]), _size(other._size) {
	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator =(const Array& other) {
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range"); // standard exception
	return _data[index];
}

template <typename T>
size_t Array<T>::size() const {return _size;}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	for (size_t i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	return os;
}