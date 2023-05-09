#pragma once

#include "../include/AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &other);
		
		Ice& operator=(const Ice &rhs);
		~Ice();

		AMateria* clone(void) const;
		void use (ICharacter & target);
	private:

};