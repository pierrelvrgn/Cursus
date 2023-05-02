#include "Fixed.hpp"

Fixed::Fixed()
: _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=( const Fixed &f )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = f.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}
