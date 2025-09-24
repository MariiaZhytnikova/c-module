#pragma once

#include <cstddef>

template <typename TypeValue, typename F>
void iter(TypeValue* array, size_t size, F func) {
	if (!array)
		return;
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}