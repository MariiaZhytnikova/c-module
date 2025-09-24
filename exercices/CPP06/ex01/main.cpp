#include "Serializer.hpp"
#include <iostream>

int main() {
try {
		Data* data = new Data;
		data->num = 25;
		data->string = "bananas";

		std::cout << "We have: "<< data->num << data->string << std::endl;
		uintptr_t raw = Serializer::serialize(data);
		Data* recovered = Serializer::deserialize(raw);
		std::cout << "Do we still have? "<< recovered->num << recovered->string << std::endl;
		delete data;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Allocation failed: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}