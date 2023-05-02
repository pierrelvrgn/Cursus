#include "Zombie.hpp"

int main()
{
	int		count = 0;
	Zombie	*horde = zombieHorde(count, "zombie");

	for (int i = 0; i < count; i++)
		horde[i].announce();
	delete [] horde;
}
