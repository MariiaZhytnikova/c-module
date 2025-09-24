#pragma once

template <typename TypeValue>
void swap(TypeValue& a, TypeValue& b) {
	TypeValue tmp = a;
	a = b;
	b = tmp;
}

template <typename TypeValue>
TypeValue const& min(TypeValue const& a, TypeValue const& b) {
	return (a < b ? a : b);
}

template <typename TypeValue>
TypeValue const& max(TypeValue const& a, TypeValue const& b) {
	return (a > b ? a : b);
};