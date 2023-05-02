#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main()
{
	srand(time(NULL));
	Base* pointer = generate();
	Base* tmp = generate();
	Base& ref = *tmp;
	identify(pointer);
	identify(ref);
	delete pointer;
	delete tmp;
}
