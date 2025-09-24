#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		std::cout << "Dog assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "\033[37m" << "Bark bark bark!" << "\033[0m" << std::endl;
}