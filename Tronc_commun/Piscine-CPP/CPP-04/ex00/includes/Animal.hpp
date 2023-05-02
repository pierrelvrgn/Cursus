#pragma once
#include <iostream>

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
