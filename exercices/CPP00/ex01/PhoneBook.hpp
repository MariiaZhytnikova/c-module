#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"
#include <iostream>

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount;
		int		nextIndex;
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(const Contact& contact);
		void	displaySummary() const;
		void	displayContact(int index) const;
		int		getContactCount() const;
};

#endif
