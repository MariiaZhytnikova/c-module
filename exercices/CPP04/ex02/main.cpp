#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// AAnimal a;
	// AAnimal* aa = new AAnimal();

	std::cout << "\033[33mCreating animals\033[0m" << std::endl;
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << "\n\033[33mMaking sounds\033[0m" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n\033[33mChecking types\033[0m" << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\n\033[33mDeleting animals\033[0m" << std::endl;
	delete dog;
	delete cat;

return 0;
}
