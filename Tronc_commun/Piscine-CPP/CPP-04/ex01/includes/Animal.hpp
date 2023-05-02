#pragma once
#include <iostream>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

class	Animal
{
	public:
		Animal();
		Animal(std::string);
		Animal( const Animal &C);
		virtual ~Animal();
		Animal	&operator=(const Animal &C);
		const std::string	getType() const;
		virtual void	makeSound() const ;
	protected:
		std::string	_type;
};
