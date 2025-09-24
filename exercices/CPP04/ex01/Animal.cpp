#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		std::cout << "Animal assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

std::string Animal::getType() const{
	return type;
}

void Animal::makeSound() const{
	std::cout << "\033[37m" << "Animal make some sound!" << "\033[0m" << std::endl;
}