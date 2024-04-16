#include "ScavTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const std::string& Name)
	: ClapTrap(Name, ST_HP, ST_ENERGY, ST_DAMAGE) {
	std::cout << "ScavTrap parametrized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& src)
	: ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName()
			  << " destroyed\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		std::cout
			<< "ScavTrap copy assignment operator called\n";
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName()
			  << " has entered gate keeper mode\n";
}

/* -------------------------------- override -------------------------------- */

void ScavTrap::attack(const std::string& target) {
	if (this->PayEnergy()) {
		std::cout << "ScavTrap " << this->getName()
				  << " attacks " << target << ", causing "
				  << this->getAttackDamage()
				  << " points of damage\n";
	} else {
		std::cout << "ScavTrap " << this->getName()
				  << " is out of energy\n";
	}
}
