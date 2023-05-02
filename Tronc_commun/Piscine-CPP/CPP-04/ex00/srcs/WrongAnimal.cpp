#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
:_type("Random Wronganimal")
{
	std::cout << "Random WrongAnimal Constructor called !" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type)
:_type(type)
{
	std::cout << "WrongAnimal Constructor with arg called !" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called !" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << _type << ": Destructor called !" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &C)
{
	this->_type = C._type;
	std::cout << " Operator = called !" << std::endl;
	return *this;
}

const std::string	WrongAnimal::getType() const
{
	return this->_type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Random sound" << std::endl;
}
