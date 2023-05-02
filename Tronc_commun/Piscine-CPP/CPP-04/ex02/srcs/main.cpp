#include "../includes/AAnimal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	AAnimal *fifty_fifty[10];

	std::cout << "=======================================" << std::endl;
	std::cout << "=           MANDATORY TESTS           =" << std::endl;
	std::cout << "=======================================" << std::endl;


	std::cout << "==========================" << std::endl;
	std::cout << "=        Constructor     =" << std::endl;
	std::cout << "==========================" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		fifty_fifty[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 5; i < 10; i++)
	{
		fifty_fifty[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==========================" << std::endl;
	std::cout << "=        MakeSound       =" << std::endl;
	std::cout << "==========================" << std::endl;

	for (int i = 0; i < 10; i++)
		fifty_fifty[i]->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "==========================" << std::endl;
	std::cout << "=        Destructor      =" << std::endl;
	std::cout << "==========================" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		delete fifty_fifty[i];
		std::cout << std::endl;
	}

	std::cout << "=======================================" << std::endl;
	std::cout << "=             BONUS TESTS             =" << std::endl;
	std::cout << "=======================================" << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	// AAnimal test;
	// test.getType();

	return 0;
}
