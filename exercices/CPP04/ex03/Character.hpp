#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* inventory[4];

	public:
		Character();
		Character(std::string const& name);
		Character(Character const& other);
		Character &operator=(Character const & other);
		~Character();


		std::string const& getName() const override;

		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif
