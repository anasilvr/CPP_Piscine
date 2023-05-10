#pragma once

#include "../include/AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &other);
		
		Cure& operator=(const Cure &rhs);
		~Cure();

		AMateria* clone(void) const;
		void use (ICharacter & target);
	private:

};