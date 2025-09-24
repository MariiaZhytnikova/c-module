#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other){
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		std::cout << "Cure assigment operator called" << std::endl;
		AMateria::operator=(other);
	}
	return *this;
}

AMateria* Cure::clone() const {
	AMateria* m = new Cure(*this);
	std::cout << "\033[31mCure clone called\033[0m" << std::endl;
	getGlobalManager().add(m);
	return m;
}

void Cure::use(ICharacter& target) {
	std::cout << "\033[37m" << "* heals " << target.getName() << "’s wounds *\n" << "\033[0m" ;
}
