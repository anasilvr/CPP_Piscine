#pragma once

#include "../include/AMateria.hpp"

class AMateria;

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

		MateriaSource & operator=(const MateriaSource &rhs);
	private:
		AMateria *_list[4];
};