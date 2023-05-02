#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test1("Test1", 5);
		Bureaucrat test2("Test2", 149);
		std::cout << "===================================" << std::endl;
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << "===================================" << std::endl;
		test1.increaseGrade();
		test2.decreaseGrade();
		std::cout << "===================================" << std::endl;
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << "===================================" << std::endl;
		test1.increaseGrade();
		test2.decreaseGrade();
		std::cout << "===================================" << std::endl;
		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << "===================================" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
