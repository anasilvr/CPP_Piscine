
#include "../include/Character.hpp"

// Default constructor
Character::Character(string const n) : _name(n) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_dropped[i] = NULL;
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
		_name = rhs.getName();
		for (int i = 0; i < 4; i++) {
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++) {
			if (rhs._dropped[i])
				_dropped[i] = rhs._dropped[i]->clone();
			else
				_dropped[i] = NULL;
		}
	}
	return *this;
}

// Default destructor
Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		if (_dropped[i])
			delete _dropped[i];
		_dropped[i] = NULL;
	}
	cout << RED << "Character " << _name << " destroyed." RESET << endl;
	return;
}


std::string const & Character::getName() const { return (_name); }	

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
//			cout << RED << m->getType();
//			cout << " added to the inventory at _inventory[" << i << "]";
//			cout << endl;
			return ;
		}
	}
	delete m;
	cout << RED "Error: Inventory is full." RESET << endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		cout << RED "_inventory[] only has 4 slots. Invalid index. Try again." << endl;
		return ;
	}
	for (int i = 0; i < 100; i++) {
		if (!_dropped[i]) {
			_dropped[i] = _inventory[idx];
			cout << RED "_inventory [" << idx << "][";
			cout << _inventory[idx]->getType();
			cout << "] unequiped." << endl;
			_inventory[idx] = nullptr;
			return ;
		}
		else
			cout << RED "_inventory[" << idx << "] is empty already." << endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx]) {
			_inventory[idx]->use(target);
		}
		else
			cout << RED "_inventory[" << idx << "] is empty. Nothing to use." << endl;
	}
	else
		cout << RED "_inventory[] only has 4 slots. Invalid index. Try again." RESET << endl;
}