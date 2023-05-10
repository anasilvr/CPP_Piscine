#pragma once

#include <iostream>
#include "../include/Character.hpp"
#include "../include/colors.hpp"

using std::string;
using std::cout;
using std::endl;

class ICharacter;

// Class declaration
class AMateria {
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		
		std::string const& getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria& operator=(const AMateria &rhs);
	protected:
		std::string _type;
};