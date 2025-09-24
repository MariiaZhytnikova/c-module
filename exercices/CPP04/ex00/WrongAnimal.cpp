#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy operator called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		std::cout << "WrongAnimal assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const{
	return type;
}

void WrongAnimal::makeSound() const{
	std::cout << "\033[37m" << "WrongAnimal make some WrongAnimal sound!" << "\033[0m" << std::endl;
}