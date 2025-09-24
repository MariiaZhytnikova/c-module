#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;
delete i;

const int size = 10;
Animal* animals[size];
std::cout << "\n     Out Pets Created\n";
for (int i = 0; i < size; i++) {
	if (i % 2 == 0)
		animals[i] = new Dog();
	else
		animals[i] = new Cat();
}

std::cout << "\n     Pets Make Sounds\n";
for (int i = 0; i < size; i++)
	animals[i]->makeSound();

std::cout << "\n     It is too loud, so ...\n";
for (int i = 0; i < size; i++) {
	delete animals[i];
}

std::cout << "\n     Copy check...\n";

Dog* original = new Dog();
Dog* copy = nullptr;
copy = new Dog(*original);

std::cout << "\n";
std::cout << "Give some ideas to our original Dog...\n";
original->getBrain()->setIdea("I want to eat!", 0);
original->getBrain()->setIdea("I want to sleep!", 1);
std::cout << "\033[37m" << "[0] " << original->getBrain()->getIdea(0) << "\033[0m" << std::endl;
std::cout << "\033[37m" << "[1] " << original->getBrain()->getIdea(1) << "\033[0m" << std::endl;

std::cout << "\n";
std::cout << "Check ideas of copy...\n";
std::cout << "\033[37m" << "[0] " << copy->getBrain()->getIdea(0) << "\033[0m" << std::endl;
std::cout << "\033[37m" << "[1] " << copy->getBrain()->getIdea(1) << "\033[0m" << std::endl;

std::cout << "\n";
std::cout << "Lets create copy Other from original dog with ideas\n";
Dog* copyOther = nullptr;
copyOther = new Dog(*original);

std::cout << "\n";
std::cout << "Check ideas of copyOther...\n";
std::cout << "\033[37m" << "[0] " << copyOther->getBrain()->getIdea(0) << "\033[0m" << std::endl;
std::cout << "\033[37m" << "[1] " << copyOther->getBrain()->getIdea(1) << "\033[0m" << std::endl;

std::cout << "\n";
std::cout << "Give some ideas to our copy of Dog...\n";

copy->getBrain()->setIdea("I want to dig!", 0);
copy->getBrain()->setIdea("I want to bite!", 1);
std::cout << "\033[37m" << "[0] " << copy->getBrain()->getIdea(0) << "\033[0m" << std::endl;
std::cout << "\033[37m" << "[1] " << copy->getBrain()->getIdea(1) << "\033[0m" << std::endl;

std::cout << "\n";
std::cout << "Original dogs ideas are still\n";
std::cout << "\033[37m" << "[0] " << original->getBrain()->getIdea(0) << "\033[0m" << std::endl;
std::cout << "\033[37m" << "[1] " << original->getBrain()->getIdea(1) << "\033[0m" << std::endl;

std::cout << "\n";

delete original;
delete copy;
delete copyOther;

return 0;
}
