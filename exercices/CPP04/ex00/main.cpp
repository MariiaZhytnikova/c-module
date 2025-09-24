#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* metaWrong = new WrongAnimal();
const WrongAnimal* k = new WrongCat();

std::cout << std::endl;

std::cout << "Type of j is: " << j->getType() << " and its sounds like:" << std::endl;
j->makeSound();
std::cout << "Type of i is: " << i->getType() << " and its sounds like:" << std::endl;
i->makeSound();
std::cout << std::endl;
std::cout << "Meta is just an animal and its sounds like:" << std::endl;
meta->makeSound();
std::cout << std::endl;
std::cout << "k is Wrong cat, and its make wrong sound:" << std::endl;
k->makeSound();

std::cout << "metaWrong is Wrong animal, and its sounds like:" << std::endl;
metaWrong->makeSound();
std::cout << std::endl;
delete meta;
delete j;
delete i;
delete metaWrong;
delete k;
return 0;
}
