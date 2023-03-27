#pragma once
#include <iostream>
#include <string>


class Zombie {

public:
	Zombie( std::string name );
	~Zombie( void );

	void setName( std::string name );
	std::string getName( void ) const;

	void announce( void );

private:
	std::string _name;
};


Zombie* newZombie( std::string name );
void randomChump( std::string name );
