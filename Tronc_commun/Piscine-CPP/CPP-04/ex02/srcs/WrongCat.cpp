#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
:WrongAnimal("WrongCat")
{
	std::cout << _type << ": Constructor called !" << std::endl;
}

WrongCat::WrongCat( const WrongCat &C)
: WrongAnimal(C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called !" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << _type << ": Destructor called !" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &C)
{
	std::cout << " Operator = called !" << std::endl;
	this->_type = C._type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Miaow wrong" << std::endl;
}
