#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap("random", 100, 100, 30)
{
	std::cout << "Fragtrap constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap param constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap &C )
{
	std::cout << "Fragtrap copy constructor" << std::endl;
	*this = C;
}

FragTrap::~FragTrap( void )
{
	std::cout << "Fragtrap " << _name << " destructor" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "High Five ?" << std::endl;
}