#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* metaaa = new WrongAnimal();
	const WrongAnimal* d = new WrongCat();
	std::cout << d->getType() << " " << std::endl;
	d->makeSound(); //will output the cat sound!
	metaaa->makeSound();

	delete meta;
	delete j;
	delete i;
	delete metaaa;
	delete d;

	return 0;
}
