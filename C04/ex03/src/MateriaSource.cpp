#include "../include/MateriaSouce.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_list[i] = NULL;
	cout << MAG << "MateriaSource created." RESET << endl;

}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
	cout << MAG << "MateriaSource created by copy." RESET << endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_list[i]) {
			delete _list[i];
			_list[i] = NULL;
		} 
	}
	cout << MAG << "MateriaSource destroyed." RESET << endl;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++){
		if (!_list[i]) {
			_list[i] = m;
//			cout << MAG <<"learnedMateria: " << m->getType() << " at _list[" << i << "]" << endl;
			return;
		}
	}
	delete m;
	cout << MAG << "Error: Máx. numbers of materias reached." RESET << endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++){
		if (_list[i]->getType() == type)
			return (_list[i]->clone());
	}
	cout << MAG << "Unkown materia. Aborting creation..." RESET << endl;
	return (0);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			delete _list[i];
		for (int i = 0; i < 4; i++)
			_list[i] = rhs._list[i]->clone();
	}
	return (*this);
}
