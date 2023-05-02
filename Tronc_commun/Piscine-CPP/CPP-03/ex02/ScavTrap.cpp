#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap("random", 100, 50, 20)
{
	std::cout << "Scavtrap constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap param constructor" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &C )
{
	std::cout << "Scavtrap copy constructor" << std::endl;
	*this = C;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "Scavtrap " << _name << " destructor" << std::endl;
	return ;
}

void	ScavTrap::attack( const std::string &target )
{
	_energy_points--;
	std::cout << "Scavtrap " << _name << " attacks " << target << ", causing "<< _attack_damage << " points of damage!" << std::endl;
	if (_energy_points < 1)
		std::cout << _name << " has no more energy" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "Scavtrap -> Gate Keeper" << std::endl;
}