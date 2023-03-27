#pragma once
#include <iostream>
#include <string>

class Weapon {

public:
	Weapon( std::string type );
	~Weapon( void );

	void setType( std::string type );
	std::string const& getType( void );

private:
	std::string _type;
};