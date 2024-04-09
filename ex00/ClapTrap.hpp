#pragma once
#include <iostream>
#include <string>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const& rhs);
	void      attack(const std::string& target);
	void      takeDamage(unsigned int amount);
	void      beRepaired(unsigned int amount);

private:
	std::string Name;
	int         Hit_points;
	int         Energy_points;
	int         Attack_damage;
};

// std::ostream& operator<<(std::ostream& o, ClapTrap const& i);
