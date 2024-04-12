#include "FragTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string Name)
	: ClapTrap(Name, FT_HP, FT_ENERGY, FT_DAMAGE) {
	std::cout << "FragTrap parametrized constructor called\n";
}

FragTrap::FragTrap(const FragTrap& src) {
	std::cout << "FragTrap copy constructor called\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName()
			  << " destroyed\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		std::cout
			<< "FragTrap copy assignment operator called\n";
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->getName()
			  << " high-fives all the guys!\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */