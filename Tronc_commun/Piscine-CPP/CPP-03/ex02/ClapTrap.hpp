#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage);
		ClapTrap( const ClapTrap &C );
		~ClapTrap( void );
		ClapTrap	&operator=( const ClapTrap &C );
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
};

#endif