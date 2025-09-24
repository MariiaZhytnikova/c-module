#pragma once

#include <algorithm>
#include <stdexcept>

// auto automatically deduce the type of a variable from its initializer
//(typename T::iterator)

template <typename T>
auto easyfind(T& container, int value) {
	auto element = std::find(container.begin(), container.end(), value);
	if (element == container.end())
		throw std::runtime_error("Not in container");
	return element;
}
