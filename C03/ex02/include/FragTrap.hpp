#pragma once
#include "../include/ClapTrap.hpp"

# ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string);
		FragTrap(const FragTrap &);

		FragTrap& operator=(const FragTrap &rhs);

		~FragTrap();
	
		void highFivesGuys(void);
	private:

};

std::ostream& operator<<(std::ostream& out, FragTrap const& arg);

#endif