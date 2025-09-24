#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& other) : AAnimal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain); 
	type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		this->type = other.type;
	}
	std::cout << "Cat assigment operator called" << std::endl;
	return *this;
}

void Cat::setBrain(Brain* newBrain) {
	if (brain)
		delete brain;
	brain = new Brain(*newBrain);
}

Brain* Cat::getBrain() const {
	return brain;
}

void Cat::makeSound() const {
	std::cout << "Cat make some sound: meow meow meow!" << std::endl;
}