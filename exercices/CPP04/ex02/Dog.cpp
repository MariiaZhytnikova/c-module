#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
	type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		this->type = other.type;
	}
	std::cout << "Dog assigment operator called" << std::endl;
	return *this;
}

void Dog::setBrain(Brain* newBrain) {
	if (brain)
		delete brain;
	brain = new Brain(*newBrain);
}

Brain* Dog::getBrain() const {
	return brain;
}

void Dog::makeSound() const {
	std::cout << "Dog make some sound: bark bark bark!" << std::endl;
}