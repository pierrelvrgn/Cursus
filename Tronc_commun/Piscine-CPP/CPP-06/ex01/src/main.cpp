#include <iostream>
#include "../includes/Data.hpp"

int main()
{
	Data test;

	test.test1 = "ouioui baguette";
	test.test2 = 76845;
	std::cout << "test1: " << test.test1 << std::endl;
	std::cout << "test2: " << test.test2 << std::endl;
	std::cout << "======================================" << std::endl;
	uintptr_t test_serialise = serialize(&test);
	Data* teeest = deserialize(test_serialise);
	std::cout << "test1: " << teeest->test1 << std::endl;
	std::cout << "test2: " << teeest->test2 << std::endl;
}
