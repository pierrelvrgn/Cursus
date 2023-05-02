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
		Fixed					&operator=( const Fixed &f );
		bool					operator>( const Fixed &f )const ;
		bool					operator<( const Fixed &f )const ;
		bool					operator>=( const Fixed &f )const ;
		bool					operator<=( const Fixed &f )const ;
		bool					operator==( const Fixed &f )const ;
		bool					operator!=( const Fixed &f )const ;
		Fixed					operator+( const Fixed &f );
		Fixed					operator-( const Fixed &f );
		Fixed					operator*( const Fixed &f );
		Fixed					operator/( const Fixed &f );
		Fixed					&operator++();
		Fixed					operator++(int);
		Fixed					&operator--();
		Fixed					operator--(int);
		int						getRawBits( void ) const;
		void					setRawBits( int const raw );
		float					toFloat( void ) const;
		int						toInt( void ) const;
		static Fixed			min(Fixed &f1, Fixed &f2);
		static Fixed			min(Fixed const &f1, Fixed const &f2);
		static Fixed			max(Fixed &f1, Fixed &f2);
		static Fixed			max(Fixed const &f1, Fixed const &f2);

	private:
		int					_fixed;
		static const int	_bytes = 8;
};

std::ostream	&operator<<(std::ostream& out, const Fixed& f);
