#ifndef MATERIAMANAGER_HPP
#define MATERIAMANAGER_HPP

#include "AMateria.hpp"

class MateriaManager {
private:
	AMateria** materiaList;
	int capacity;
	int size;
	void expand();

public:
	MateriaManager();
	MateriaManager(const MateriaManager& other);
	MateriaManager& operator=(const MateriaManager& other);
	~MateriaManager();

	void add(AMateria* m);
	void clear();
};

MateriaManager& getGlobalManager();

#endif
