#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <array>

class Brain
{
	private:
		std::array<std::string, 100> ideas;
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(const std::string& idea, int index);
		std::string getIdea(int index) const;
};

#endif