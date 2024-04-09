#include "ScavTrap.hpp"

int main() {
	ScavTrap zombie("Zombie");
	ScavTrap human("Human");

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

	zombie.guardGate();
	human.guardGate();
	return 0;
}