#pragma once
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat();
		Cat( const Cat &C);
		~Cat();
		Cat	&operator=(const Cat &C);
		void	makeSound() const;
		Brain	*getBrain();
	private:
		Brain *_brain;
};
