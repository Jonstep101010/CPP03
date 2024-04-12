#pragma once
#include <string>

#define DEFAULT_HP 10
#define DEFAULT_ENERGY 10
#define DEFAULT_DAMAGE 0

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(std::string Name, int HitPoints, int Energy,
			 int Damage);
	ClapTrap(ClapTrap const& src);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const& rhs);

	// members
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// getters and setters
	std::string getName() const;
	int         getHitPoints() const;
	int         getEnergyPoints() const;
	int         getAttackDamage() const;
	void        setName(std::string Name);
	void        setHitPoints(int hit_points);
	void        setEnergyPoints(int energy_points);
	void        setAttackDamage(int attack_damage);

	// helpers
	bool PayEnergy();
	void printStats(std::string header) const;

private:
	std::string Name;
	int         Hit_points;
	int         Energy_points;
	int         Attack_damage;
};
