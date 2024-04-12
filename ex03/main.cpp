#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	DiamondTrap zombie("Zombie");
	DiamondTrap human("Human");
	DiamondTrap copy(zombie);

	copy.printStats("Copy");

	zombie.printStats("Default");

	zombie.setAttackDamage(5);
	human.setAttackDamage(3);
	zombie.attack("Human");
	human.takeDamage(zombie.getAttackDamage());
	human.beRepaired(7);
	human.attack("Zombie");
	zombie.takeDamage(human.getAttackDamage());

	zombie.printStats("Zombie");
	human.printStats("Human");

	zombie.attack("Human");
	human.takeDamage(zombie.getAttackDamage());
	human.attack("Zombie");
	zombie.takeDamage(human.getAttackDamage());
	zombie.attack("Human");
	human.takeDamage(zombie.getAttackDamage());
	human.attack("Zombie");
	zombie.takeDamage(human.getAttackDamage());

	zombie.printStats("Zombie");
	human.printStats("Human");

	human.attack("Zombie");
	zombie.takeDamage(human.getAttackDamage());
	zombie.printStats("Zombie");
	human.printStats("Human");

	zombie.highFivesGuys();
	std::cout << "Human of DiamondTrap attacks as ScavTrap\n";
	human.attack("Zombie");
	human.whoAmI();
	return 0;
}