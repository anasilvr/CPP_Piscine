
#include "../include/Character.hpp"

// Default constructor
Character::Character(string const n) : _name(n) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << RED << "Character " << _name << " created." RESET << endl;
	return;
}

// Copy constructor
Character::Character(const Character &other) {
  *this = other;
  cout << RED << "Character " << _name << " copied from " << other._name << "." RESET << endl;
  return;
}

// Copy assignment overload
Character &Character::operator=(const Character &rhs) {
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
			_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

// Default destructor
Character::~Character() {
	cout << RED << "Character " << _name << " destroyed." RESET << endl;
	//destroy inventory?
	return;
}


std::string const & Character::getName() const {
	return (_name);
}	

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i]) {
			_inventory[i] = m;
			cout << m << " added to the inventory at slot nb. [" << i << "]" << endl;
			return ;
		}
	}
	cout << "Inventory is full." << endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] != NULL) {
			_inventory[idx] = nullptr;
			cout << RED " Inventory [" << idx << "] Type: "<< _inventory[idx]->getType();
			cout << " unequiped." << endl;
		}
		else
			cout << RED " Inventory [" << idx << "] is empty already." << endl;
	}
	else
		cout << RED "Inventory only has 4 slots. Invalid index. Try again." RESET << endl;

}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] != NULL) {
			_inventory[idx]->use(target);
			cout << RED " Inventory [" << idx << "] Type: "<< _inventory[idx]->getType();
			cout << " unequiped." << endl;
		}
		else
			cout << RED " Inventory [" << idx << "] is empty." << endl;
	}
	else
		cout << RED "Inventory only has 4 slots. Invalid index. Try again." RESET << endl;
}