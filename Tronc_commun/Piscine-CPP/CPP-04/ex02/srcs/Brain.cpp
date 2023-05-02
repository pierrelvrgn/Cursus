#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::string tmp[] = {
		"I want to eat",
		"I want to drink",
		"I want to sleep"
	};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = tmp[rand() % 3];
	std::cout << BLU << "Brain constructor" << WHT << std::endl;
}

Brain::Brain(const Brain &C)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = C._ideas[i];
	std::cout << BLU << "Brain constructor copy" << WHT << std::endl;
}

Brain &Brain::operator=(const Brain &C)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = C._ideas[i];
	std::cout << BLU << "Brain operator =" << WHT << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << BLU << "Brain destructor" << WHT << std::endl;
}

