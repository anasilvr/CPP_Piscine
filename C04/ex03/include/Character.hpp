#pragma once

#include "../include/AMateria.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	public:
		Character(string const n);
		Character(const Character &other);
		~Character();
		
		string const & getName() const;
		
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	
		Character& operator=(const Character &rhs);
	
	private:
		string		_name;
		AMateria	*_inventory[4];
};