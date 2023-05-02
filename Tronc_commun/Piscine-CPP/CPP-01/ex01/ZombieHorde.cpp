#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 0)
		return 0;
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
