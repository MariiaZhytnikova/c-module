#include "MateriaManager.hpp"
#include <iostream>

static MateriaManager gManager;

MateriaManager& getGlobalManager() {
	return gManager;
}

MateriaManager::MateriaManager()
	: capacity(10), size(0)
{
	materiaList = new AMateria*[capacity];
	for (int i = 0; i < capacity; ++i)
		materiaList[i] = nullptr;
}

MateriaManager::MateriaManager(const MateriaManager& other)
	: capacity(other.capacity), size(other.size)
{
	materiaList = new AMateria*[capacity];
	for (int i = 0; i < size; ++i)
		materiaList[i] = other.materiaList[i] ? other.materiaList[i]->clone() : nullptr;
	for (int i = size; i < capacity; ++i)
		materiaList[i] = nullptr;
}

MateriaManager& MateriaManager::operator=(const MateriaManager& other)
{
	if (this != &other) {
		clear();
		delete[] materiaList;

		capacity = other.capacity;
		size = other.size;
		materiaList = new AMateria*[capacity];
		for (int i = 0; i < size; ++i)
			materiaList[i] = other.materiaList[i] ? other.materiaList[i]->clone() : nullptr;
		for (int i = size; i < capacity; ++i)
			materiaList[i] = nullptr;
	}
	return *this;
}

MateriaManager::~MateriaManager() {
	clear();
	delete[] materiaList;
}

void MateriaManager::expand() {
	int newCapacity = capacity * 2;
	AMateria** newList = new AMateria*[newCapacity];
	for (int i = 0; i < newCapacity; ++i)
		newList[i] = (i < size) ? materiaList[i] : nullptr;
	delete[] materiaList;
	materiaList = newList;
	capacity = newCapacity;
}

void MateriaManager::add(AMateria* m) {
	if (!m) return;

	if (size >= capacity)
		expand();

	materiaList[size++] = m;
}

void MateriaManager::clear() {
	for (int i = 0; i < size; ++i) {
		std::cout << "\033[31mDelete all stored AMateria \033[0m" << i << std::endl;
		delete materiaList[i];
		materiaList[i] = nullptr;
	}
	size = 0;
}
