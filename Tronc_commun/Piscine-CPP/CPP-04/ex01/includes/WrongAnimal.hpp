#pragma once
#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string);
		WrongAnimal( const WrongAnimal &C);
		~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &C);
		const std::string	getType() const;
		void	makeSound() const ;
	protected:
		std::string	_type;
};
