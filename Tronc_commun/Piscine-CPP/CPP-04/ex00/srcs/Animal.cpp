#include "../includes/Animal.hpp"

Animal::Animal()
:_type("Random animal")
{
	std::cout << "Random Animal Constructor called !" << std::endl;
}
Animal::Animal(std::string type)
:_type(type)
{
	std::cout << "Animal: " << _type << " Constructor with arg called !" << std::endl;
}

Animal::Animal( const Animal &C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: " << _type << " Destructor called !" << std::endl;
}

Animal	&Animal::operator=(const Animal &C)
{
	this->_type = C._type;
	std::cout << " Operator = called !" << std::endl;
	return *this;
}

const std::string	Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << "Random sound" << std::endl;
}
