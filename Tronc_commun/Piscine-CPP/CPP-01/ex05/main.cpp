#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harl;

	if (argc == 1)
	{
		std::cout << "DEBUG: " << std::endl;
		harl.complain("DEBUG");
		std::cout << "INFO: " << std::endl;
		harl.complain("INFO");
		std::cout << "WARNING: " << std::endl;
		harl.complain("WARNING");
		std::cout << "ERROR: " << std::endl;
		harl.complain("ERROR");
	}
	else
	{
		for(int i = 1; i < argc; i++)
			harl.complain(argv[i]);
	}
}
