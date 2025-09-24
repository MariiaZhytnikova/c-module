#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	std::string command;

	std::cout << "Type one of the commands: ADD to add a contact, SEARCH to search, or EXIT to quit." << std::endl;

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command);
		
		// Checks for signals like Ctrl + D or Ctrl + C
		if (std::cin.eof()) {
			std::cout << "\nExiting..." << std::endl;
			break;
		}

		if (command == "ADD") {
			Contact newContact;
			std::string input;

			std::cout << "First Name: ";
			std::getline(std::cin, input);
			newContact.setFirstName(input);

			std::cout << "Last Name: ";
			std::getline(std::cin, input);
			newContact.setLastName(input);

			std::cout << "Nickname: ";
			std::getline(std::cin, input);
			newContact.setNickname(input);

			std::cout << "Phone Number: ";
			std::getline(std::cin, input);
			newContact.setPhoneNumber(input);

			std::cout << "Darkest Secret: ";
			std::getline(std::cin, input);
			newContact.setDarkestSecret(input);

			phonebook.addContact(newContact);
		}
		else if (command == "SEARCH") {
			phonebook.displaySummary();

			std::cout << "Enter contact index to view details: ";
			std::getline(std::cin, command);
			int index = -1;

			try {
				index = std::stoi(command);
			} catch (...) {
				std::cout << "Invalid input." << std::endl;
				continue;
			}

			if (index >= 0 && index < phonebook.getContactCount()) {
				phonebook.displayContact(index);
			} else {
				std::cout << "Invalid index." << std::endl;
			}
		}
		else if (command == "EXIT") {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else {
			std::cout << "Please use ADD, SEARCH or EXIT." << std::endl;
		}
	}

	return 0;
}
