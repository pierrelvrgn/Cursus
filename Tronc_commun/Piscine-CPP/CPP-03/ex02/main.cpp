#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	a("test1");
	ScavTrap	b("test2");
	FragTrap	c;
	FragTrap	d("test3");

	d.highFivesGuys();
	d.takeDamage(3);
	d.beRepaired(3);
	d.attack("Eric");
}