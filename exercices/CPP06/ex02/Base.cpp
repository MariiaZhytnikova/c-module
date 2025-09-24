#include "Base.hpp"
#include "Classes.hpp"
#include <ctime>

Base::~Base() {}

Base * generate(void) {
	std::srand(std::time(nullptr));

	int random = std::rand() % 3;
	switch (random) {
		case 0: {
			A* a = new (std::nothrow) A();
			if (!a) {
				std::cerr << "Allocation failed for A" << std::endl;
				return nullptr;
			}
			std::cout << "A type was created" << std::endl;
			return a;
		}
		case 1: {
			B* b = new (std::nothrow) B();
			if (!b) {
				std::cerr << "Allocation failed for B" << std::endl;
				return nullptr;
			}
			std::cout << "B type was created" << std::endl;
			return b;
		}
		case 2: {
			C* c = new (std::nothrow) C();
			if (!c) {
				std::cerr << "Allocation failed for C" << std::endl;
				return nullptr;
			}
			std::cout << "C type was created" << std::endl;
			return c;
		}
		default:
			return nullptr;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "pointer type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer type: C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "reference type: A" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "reference type: B" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "reference type: C" << std::endl;
		return;
	} catch (std::exception&) {}
}