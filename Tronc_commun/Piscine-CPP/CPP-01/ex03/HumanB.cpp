#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon)
		std::cout << this->_weapon->getType() << std::endl;
	else
		std::cout << " fists" << std::endl;
}
