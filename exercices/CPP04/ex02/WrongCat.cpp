#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "WrongCat copy operator called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		std::cout << "Cat assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat make some WrongCat sound" << std::endl;
}