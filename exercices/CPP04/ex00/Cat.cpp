#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		std::cout << "Cat assigment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "\033[37m" << "Meow meow meow!" << "\033[0m" << std::endl;
}