#include "../includes/Dog.hpp"

Dog::Dog()
:Animal("Dog")
{
	std::cout << RED << _type << ": Constructor called" << WHT << std::endl;
	_brain = new Brain();
}

Dog::Dog( const Dog &C)
: Animal(C)
{
	_brain = new Brain(*C._brain);
	_type = C._type;
	std::cout << RED << _type << ": Copy Constructor called" << WHT << std::endl;
}

Brain	*Dog::getBrain()
{
	return this->_brain;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << RED << _type << ": Destructor called" << WHT << std::endl;
}

Dog	&Dog::operator=(const Dog &C)
{
	std::cout << RED << " Operator = called" << WHT << std::endl;
	delete _brain;
	_brain = new Brain(*C._brain);
	_type = C._type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << RED << "Waf" << WHT << std::endl;
}
