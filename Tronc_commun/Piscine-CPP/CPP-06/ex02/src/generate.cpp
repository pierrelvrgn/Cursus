#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base* generate()
{
	switch (rand() % 3)
	{
	case 0:
		std::cout << "generated: A" << std::endl;
		return new A();
	case 1:
		std::cout << "generated: B" << std::endl;
		return new B();
	case 2:
		std::cout << "generated: C" << std::endl;
		return new C();
	default:
		return NULL;
	}
	return new Base();
}
