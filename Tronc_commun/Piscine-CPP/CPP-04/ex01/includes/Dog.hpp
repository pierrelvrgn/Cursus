#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog &C);
		~Dog();
		Dog	&operator=(const Dog &C);
		void	makeSound() const;
		Brain	*getBrain();
	private:
		Brain *_brain;
};
