#pragma once

#include "../include/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string);
		ScavTrap(const ScavTrap &);

		ScavTrap& operator=(const ScavTrap &rhs);

		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
		bool	guardStatus() const;
	
	private:
		bool _gateKeeper;
};

std::ostream& operator<<(std::ostream& out, ScavTrap const& arg);