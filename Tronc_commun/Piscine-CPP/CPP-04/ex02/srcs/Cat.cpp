#include "../includes/Cat.hpp"

Cat::Cat()
:AAnimal("Cat")
{
	std::cout << GRN << _type << ": Constructor called" << WHT << std::endl;
	_brain = new Brain();
}

Cat::Cat( const Cat &C)
: AAnimal(C)
{
	_brain = new Brain(*C._brain);
	_type = C._type;
	std::cout << GRN << _type << ": Copy Constructor called" << WHT << std::endl;
}

Brain	*Cat::getBrain()
{
	return this->_brain;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << GRN << _type << ": Destructor called" << WHT << std::endl;
}

Cat	&Cat::operator=(const Cat &C)
{
	std::cout << GRN << " Operator = called" << WHT << std::endl;
	delete _brain;
	_brain = new Brain(*C._brain);
	_type = C._type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << GRN << "Miaow" << WHT << std::endl;
}
