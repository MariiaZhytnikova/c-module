#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {
std::cout << "▖  ▖    ▄▖              \n";
std::cout << "▛▖▞▌▌▌  ▌▌▌▌▌█▌▛▘▛▌▛▛▌█▌\n";
std::cout << "▌▝ ▌▙▌  ▛▌▚▚▘▙▖▄▌▙▌▌▌▌▙▖\n";
std::cout << "    ▄▌                  \n";
std::cout << "                        \n";
std::cout << "▄▖▌       ▄     ▌       \n";
std::cout << "▙▌▛▌▛▌▛▌█▌▙▘▛▌▛▌▙▘      \n";
std::cout << "▌ ▌▌▙▌▌▌▙▖▙▘▙▌▙▌▛▖      \n";
std::cout << "                        \n";
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;

	if (contactCount < 8)
		contactCount++;
}

static std::string formatField(const std::string& field) {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	else
		return std::string(10 - field.length(), ' ') + field;
}

void PhoneBook::displaySummary() const {
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		std::cout << std::setw(10) << i << "|"
				  << formatField(contacts[i].getFirstName()) << "|"
				  << formatField(contacts[i].getLastName()) << "|"
				  << formatField(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getContactCount() const {
	return contactCount;
}
