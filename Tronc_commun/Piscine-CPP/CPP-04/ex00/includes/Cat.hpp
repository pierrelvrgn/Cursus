#pragma once
#include <iostream>
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat( const Cat &C);
		~Cat();
		Cat	&operator=(const Cat &C);
		void	makeSound() const;
};
