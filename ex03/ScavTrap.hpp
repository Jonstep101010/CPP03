#pragma once

#include "ClapTrap.hpp"
#include <string>

#define ST_HP 100
#define ST_ENERGY 50
#define ST_DAMAGE 20

class ScavTrap : public ClapTrap {

public:
	ScavTrap();
	ScavTrap(const std::string& Name);
	ScavTrap(ScavTrap const& src);
	~ScavTrap();

	ScavTrap& operator=(ScavTrap const& rhs);

	// members
	void guardGate();

	// overrides
	void attack(const std::string& target);

private:
};
