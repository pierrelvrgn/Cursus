#include "Fixed.hpp"

Fixed::Fixed()
: _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = nb << _bytes;
}

Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = std::roundf(fl * (1 << _bytes));
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
	this->_fixed = f._fixed;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

std::ostream &operator<<(std::ostream& out, const Fixed& f)
{
	out << f.toFloat();
	return (out);
}

float Fixed::toFloat( void ) const
{
	return (float)this->_fixed / (1 << this->_bytes);
}

int Fixed::toInt( void ) const
{
	return this->_fixed >> this->_bytes;
}
