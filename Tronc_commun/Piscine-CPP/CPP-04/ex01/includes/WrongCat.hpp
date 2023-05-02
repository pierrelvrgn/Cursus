#pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat &C);
		~WrongCat();
		WrongCat	&operator=(const WrongCat &C);
		void	makeSound() const;
};
