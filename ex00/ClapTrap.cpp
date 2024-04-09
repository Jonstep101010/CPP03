#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
	: Hit_points(10), Energy_points(10), Attack_damage(0) {}

ClapTrap::ClapTrap(std::string Name)
	: Name(Name)
	, Hit_points(10)
	, Energy_points(10)
	, Attack_damage(0) {
	std::cout << "ClapTrap " << Name << " created\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
	: Hit_points(10), Energy_points(10), Attack_damage(0) {
	*this = src;
	std::cout << "ClapTrap " << Name << " created by copy\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
	if (this != &rhs) {
		this->Attack_damage = rhs.Attack_damage;
		this->Energy_points = rhs.Energy_points;
		this->Hit_points = rhs.Hit_points;
		this->Name = rhs.Name;
	}
	return *this;
}

// std::ostream& operator<<(std::ostream& o, ClapTrap const& i) {
//o << "Value = " << i.getValue();
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (Energy_points == 0) {
		std::cout << "ClapTrap " << Name << " is out of energy\n";
		return;
	}
	if (Hit_points == 0) {
		return;
	}
	std::cout << "ClapTrap " << Name << " attacks " << target
			  << ", causing " << Attack_damage
			  << " points of damage!\n";
	this->Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << Name << " takes " << amount
			  << " damage\n";
	Hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (Energy_points == 0) {
		std::cout << "ClapTrap " << Name << " is out of energy\n";
		return;
	}
	std::cout << "ClapTrap " << Name << " is repaired by "
			  << amount << " points\n";
	Hit_points += amount;
	this->Energy_points--;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */