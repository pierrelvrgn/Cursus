#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
: _name(name)
{
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << ": destroyed." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
