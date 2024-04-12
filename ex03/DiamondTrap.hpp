#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
	DiamondTrap();
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();

	// DiamondTrap& operator=(DiamondTrap const& rhs);

private:
};
