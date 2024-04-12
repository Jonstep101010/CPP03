#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	DiamondTrap(DiamondTrap const& src);
	~DiamondTrap();

	DiamondTrap& operator=(DiamondTrap const& rhs);

	void attack(std::string const& target);

	void whoAmI();

private:
	std::string Name;
};
