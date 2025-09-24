#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void setBrain(Brain* brain);
		Brain* getBrain() const;
		void makeSound() const override;
};

#endif