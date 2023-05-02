#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	a;
	ClapTrap	b("test2");
	ScavTrap	c;
	ScavTrap	d("test1");

	d.takeDamage(20);
	d.attack("test3");
	d.beRepaired(6);
	d.guardGate();
}
