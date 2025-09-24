#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		std::cout << "AMateria assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "\033[37m" << "* uses materia on " << target.getName() << " *" << "\033[0m" << std::endl;
}
