#pragma once
#include <iostream>
#include "AAnimal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &C);
		Brain &operator=(const Brain &C);
		~Brain();
	private:
		std::string	_ideas[100];
};
