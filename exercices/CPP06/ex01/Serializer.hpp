#pragma once

#include <string>
#include <cstdint>

struct Data {
	std::string	string;
	int			num;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		//It takes a pointer and converts it to the unsigned integer type uintptr_t

		static Data* deserialize(uintptr_t raw);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
};
