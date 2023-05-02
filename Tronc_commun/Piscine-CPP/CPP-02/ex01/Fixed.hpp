#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &f );
		Fixed(const int in);
		Fixed(const float fl);
		~Fixed( void );
		Fixed				&operator=( const Fixed &f );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;

	private:
		int					_fixed;
		static const int	_bytes = 8;
};

std::ostream	&operator<<(std::ostream& out, const Fixed& f);
