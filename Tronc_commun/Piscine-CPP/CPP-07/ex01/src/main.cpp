#include "../includes/iter.hpp"

int main()
{
	std::string str[] = {"Test1", "Test2", "Test3"};
	std::cout << "Test string: " << std::endl;
	::iter(str, 3, T_cout<std::string>);
	int _int[] = {568935, -64148, 6514646};
	std::cout << "==========================" << std::endl;
	std::cout << "Test Int: " << std::endl;
	::iter(_int, 3, T_cout<int>);
}
