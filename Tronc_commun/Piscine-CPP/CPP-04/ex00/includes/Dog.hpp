#pragma once
#include <iostream>
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog &C);
		~Dog();
		Dog	&operator=(const Dog &C);
		void	makeSound() const;
};
