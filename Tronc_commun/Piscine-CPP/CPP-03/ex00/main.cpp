#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap test1;
	ClapTrap test2("test2");

	test1 = test2;

	test1.attack("test_3");
	test1.takeDamage(3);
	test1.beRepaired(2);
	return (0);
}