#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &f );
		~Fixed( void );
		Fixed	&operator=( const Fixed &f );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed;
		static const int	_bytes = 8;
};
