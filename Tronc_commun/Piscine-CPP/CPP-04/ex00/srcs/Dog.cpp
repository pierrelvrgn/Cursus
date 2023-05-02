#include "../includes/Dog.hpp"

Dog::Dog()
:Animal("Dog")
{
	std::cout << _type << ": Constructor called !" << std::endl;
}

Dog::Dog( const Dog &C)
: Animal(C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called !" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type << ": Destructor called !" << std::endl;
}

Dog	&Dog::operator=(const Dog &C)
{
	std::cout << " Operator = called !" << std::endl;
	this->_type = C._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Waf" << std::endl;
}
