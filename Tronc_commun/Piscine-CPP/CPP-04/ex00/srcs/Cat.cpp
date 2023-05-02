#include "../includes/Cat.hpp"

Cat::Cat()
:Animal("Cat")
{
	std::cout << _type << ": Constructor called !" << std::endl;
}

Cat::Cat( const Cat &C)
: Animal(C)
{
	this->_type = C._type;
	std::cout << _type << ": Copy Constructor called !" << std::endl;
}

Cat::~Cat()
{
	std::cout << _type << ": Destructor called !" << std::endl;
}

Cat	&Cat::operator=(const Cat &C)
{
	std::cout << " Operator = called !" << std::endl;
	this->_type = C._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaow" << std::endl;
}
