#pragma once
#include <iostream>

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

class	AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string);
		AAnimal( const AAnimal &C);
		virtual ~AAnimal();
		AAnimal	&operator=(const AAnimal &C);
		const std::string	getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string	_type;
};
