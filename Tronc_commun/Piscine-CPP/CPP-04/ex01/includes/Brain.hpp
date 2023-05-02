#pragma once
#include <iostream>
#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(const Brain &C);
		Brain &operator=(const Brain &C);
		~Brain();
		std::string get_idea(int index) const;
	private:
		std::string	_ideas[100];
};
