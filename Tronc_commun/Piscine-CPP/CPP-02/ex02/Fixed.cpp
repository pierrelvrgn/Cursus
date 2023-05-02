#include "Fixed.hpp"

Fixed::Fixed()
: _fixed(0)
{
}

Fixed::Fixed(const int nb)
{
	this->_fixed = nb << _bytes;
}

Fixed::Fixed(const float fl)
{
	this->_fixed = std::roundf(fl * (1 << _bytes));
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed( const Fixed &f )
{
	*this = f;
}

Fixed &Fixed::operator=( const Fixed &f )
{
	this->_fixed = f._fixed;
	return (*this);
}

int Fixed::getRawBits(void) const
{
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
	return ((float)this->_fixed / (1 << this->_bytes));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_bytes);
}

Fixed &Fixed::operator++()
{
	this->_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

bool	Fixed::operator>( const Fixed &f )const
{
	if (this->_fixed > f._fixed)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<( const Fixed &f )const
{
	if (this->_fixed < f._fixed)
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=( const Fixed &f )const
{
	if (this->_fixed >= f._fixed)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=( const Fixed &f )const
{
	if (this->_fixed <= f._fixed)
		return (1);
	else
		return (0);
}

bool	Fixed::operator==( const Fixed &f )const
{
	if (this->_fixed == f._fixed)
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=( const Fixed &f )const
{
	if (this->_fixed != f._fixed)
		return (1);
	else
		return (0);
}

Fixed	Fixed::operator+( const Fixed &f )
{
	Fixed result;

	result._fixed = _fixed + f._fixed;
	return (result);
}

Fixed	Fixed::operator-( const Fixed &f )
{
	Fixed result;

	result._fixed = _fixed - f._fixed;
	return (result);
}

Fixed Fixed::operator*(Fixed const &f)
{
	Fixed result(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->_fixed);
	tmp2 = ((long)f._fixed);
	result._fixed = (tmp1 * tmp2) / (1 << this->_bytes);
	return (result);
}

Fixed	Fixed::operator/( const Fixed &f )
{
	Fixed result(*this);
	if (f._fixed != 0)
	{
		long tmp1, tmp2;

		tmp1 = ((long)this->_fixed);
		tmp2 = ((long)f._fixed);
		result._fixed = (tmp1 / tmp2) / (1 << this->_bytes);
	}
	else
		std::cout << "Error: arg == 0" << std::endl;
	return (result);
}

Fixed Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

Fixed Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}
