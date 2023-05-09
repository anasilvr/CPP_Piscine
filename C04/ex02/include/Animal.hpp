#pragma once

#include <iostream>
#include "../include/Brain.hpp"

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define RESET "\e[0m"

using std::string;
using std::cout;
using std::endl;

class AAnimal
{
protected:
	string _type;	

public:
	AAnimal();
	AAnimal(const string t);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &rhs);
	virtual	~AAnimal();	

	string	getType() const;
	void	setType(const string& t);

	virtual void makeSound() const = 0; 
};
