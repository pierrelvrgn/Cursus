#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
:_type("Random Aanimal")
{
	std::cout << "Random AAnimal Constructor called" << std::endl;
}
AAnimal::AAnimal(std::string type)
:_type(type)
{
	std::cout << "AAnimal Constructor with arg called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &C)
{
	this->_type = C._type;
	std::cout << " Operator = called" << std::endl;
	return *this;
}

const std::string	AAnimal::getType() const
{
	return this->_type;
}
