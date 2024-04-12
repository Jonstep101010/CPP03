#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
	: Hit_points(DEFAULT_HP)
	, Energy_points(DEFAULT_ENERGY)
	, Attack_damage(DEFAULT_DAMAGE) {
	std::cout << "Default ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string Name)
	: Name(Name)
	, Hit_points(DEFAULT_HP)
	, Energy_points(DEFAULT_ENERGY)
	, Attack_damage(DEFAULT_DAMAGE) {
	std::cout << "Created ClapTrap with name: " << Name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
	: Hit_points(DEFAULT_HP)
	, Energy_points(DEFAULT_ENERGY)
	, Attack_damage(DEFAULT_DAMAGE) {
	std::cout << "ClapTrap copy constructor called\n";
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << Name << " destroyed\n";
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
	std::cout << "ClapTrap " << Name << "assigned\n";
	if (this != &rhs) {
		this->Attack_damage = rhs.getAttackDamage();
		this->Energy_points = rhs.getEnergyPoints();
		this->Hit_points    = rhs.getHitPoints();
		this->Name          = rhs.getName();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (this->getHitPoints() == 0) {
		std::cout << "ClapTrap " << this->getName()
				  << " is already dead\n";
		return;
	}
	if (!this->PayEnergy()) {
		std::cout << "ClapTrap " << this->getName()
				  << " is out of energy\n";
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks "
			  << target << ", \033[38;5;131mcausing "
			  << this->getAttackDamage()
			  << " points of damage!\033[0m\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > 0) {
		if (this->getHitPoints() <= 0) {
			std::cout << "ClapTrap " << this->getName()
					  << " is already dead\n";
			return;
		}
		std::cout << "\033[38;5;214mClapTrap " << this->getName()
				  << " takes " << amount << " damage\033[0m\n";
		if ((int)amount >= this->getHitPoints()) {
			std::cout << "\033[31mClapTrap " << this->getName()
					  << " died!\033[0m\n";
			this->setHitPoints(0);
			return;
		}
		this->setHitPoints(this->getHitPoints() - (int)amount);
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (amount > 0) {
		if (this->getHitPoints() <= 0) {
			std::cout << "ClapTrap " << this->getName()
					  << " is dead already\n";
			return;
		}
		if (this->PayEnergy()) {
			std::cout << "\033[38;5;112mClapTrap "
					  << this->getName() << " is repaired by "
					  << amount << " points\033[0m\n";
			this->setHitPoints(this->getHitPoints()
							   + (int)amount);
		} else {
			std::cout << "ClapTrap " << this->getName()
					  << " is out of energy\n";
		}
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName() const { return Name; }

int ClapTrap::getHitPoints() const { return Hit_points; }

int ClapTrap::getEnergyPoints() const { return Energy_points; }

int ClapTrap::getAttackDamage() const { return Attack_damage; }

void ClapTrap::setName(std::string name) { Name = name; }

void ClapTrap::setHitPoints(int hit_points) {
	if (hit_points >= 0) {
		Hit_points = hit_points;
	} else {
		Hit_points = 0;
	}
}

void ClapTrap::setEnergyPoints(int energy_points) {
	Energy_points = energy_points;
}

bool ClapTrap::PayEnergy() {
	if (this->getEnergyPoints() > 0) {
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		return (true);
	}
	return (false);
}

void ClapTrap::setAttackDamage(int attack_damage) {
	if (attack_damage >= 0) {
		Attack_damage = attack_damage;
	} else {
		Attack_damage = 0;
	}
}

void ClapTrap::printStats(std::string header) const {
	std::cout << "\n\033[0;93m********" << header
			  << "********\n\nHitPoints: " << std::setw(6)
			  << this->getHitPoints()
			  << "\nEnergy Points: " << std::setw(2)
			  << this->getEnergyPoints()
			  << "\nAttack Points: " << std::setw(2)
			  << this->getAttackDamage() << "\033[0;39m\n\n";
}

/* ************************************************************************** */