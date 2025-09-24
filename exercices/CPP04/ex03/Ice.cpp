#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other){
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		std::cout << "Ice assigment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Ice::clone() const {
	AMateria* m = new Ice(*this);
	std::cout << "\033[31mIce clone called\033[0m" << std::endl;
	getGlobalManager().add(m);
	return m;
}

void Ice::use(ICharacter& target) {
	std::cout << "\033[37m" << "* shoots an ice bolt at " << target.getName() << " *" << "\033[0m" << std::endl;
}