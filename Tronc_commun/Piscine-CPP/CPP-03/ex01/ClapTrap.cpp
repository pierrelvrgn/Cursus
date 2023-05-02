#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:_name("random"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap Basic Constructor called : name -> random" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap Constructor with arg called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage)
:_name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
	std::cout << "ClapTrap Constructor with multiple arg called" << std::endl;
}


ClapTrap::ClapTrap( const ClapTrap &C )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = C;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl;
	return ;
}
 
ClapTrap &ClapTrap::operator=( const ClapTrap &C )
{
	std::cout << "Operator '=' called" << std::endl;
	this->_name= C._name;
	this->_hit_points= C._hit_points;
	this->_energy_points= C._energy_points;
	this->_attack_damage= C._attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "<< this->_attack_damage << " points of damage!" << std::endl;
	if (this->_energy_points < 1)
		std::cout << this->_name << " has no more energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points = this->_hit_points - amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage!" << std::endl;
	if (this->_hit_points < 1)
		std::cout << this->_name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " hit points" << std::endl;
	if (this->_energy_points < 1)
		std::cout << this->_name << " has no more energy" << std::endl;
}
