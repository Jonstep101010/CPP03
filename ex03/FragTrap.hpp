#pragma once

#include "ClapTrap.hpp"

#define FT_HP 100
#define FT_ENERGY 100
#define FT_DAMAGE 30

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string Name);
	FragTrap(FragTrap const& src);
	~FragTrap();

	FragTrap& operator=(FragTrap const& rhs);

	void highFivesGuys(void);

private:
};
