#include "DiamondTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name") {
	std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string Name)
	: ClapTrap(Name + "_clap_name"), Name(Name) {
	FragTrap::setHitPoints(FT_HP);
	ScavTrap::setEnergyPoints(ST_ENERGY);
	FragTrap::setAttackDamage(FT_ENERGY);
	std::cout << "DiamondTrap parametrized constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
	: ClapTrap(), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap copy constructor called\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->getName()
			  << " destroyed\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
	if (this != &rhs) {
		// need to inherit the assignment operator from both classes
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::attack(std::string const& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->Name
			  << " and my DiamondTrap name is "
			  << this->getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */