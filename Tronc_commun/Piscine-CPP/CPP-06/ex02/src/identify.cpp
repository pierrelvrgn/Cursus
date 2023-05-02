#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identify by pointer: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identify by pointer: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identify by pointer: C" << std::endl;
	else
		std::cerr << "bad cast" << std::endl;

}


template <typename T>
bool check_base(Base& p, std::string _base)
{
	try {(void)dynamic_cast<T&>(p); std::cout << "Identify by reference: " << _base << std::endl; return true;}
	catch (std::exception &){return false;}
}

void identify(Base& p)
{
	check_base<A>(p, "A") || check_base<B>(p, "B") || check_base<C>(p, "C");
}
