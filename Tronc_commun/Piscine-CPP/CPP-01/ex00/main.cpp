#include "Zombie.hpp"

int main()
{
	Zombie	zombie_1("zombie_1");
	Zombie	*zombie_2 = newZombie("zombie_2");
	zombie_1.announce();
	zombie_2->announce();
	randomChump("zombie_3");
	delete zombie_2;
}
