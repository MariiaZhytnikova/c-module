#include "Base.hpp"

int main() {
	Base* r = generate();
	if (!r) {
		std::cout << "pointer was not generated" << std::endl;
		return 1;
	}

	identify(r);
	identify(*r);
	
	delete r;
	return 0;
}