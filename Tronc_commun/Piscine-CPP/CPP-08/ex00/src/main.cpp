#include "../includes/easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

int main()
{
	std::list<int> list;
	std::vector<int> vector;

	for (int i = 0; i <= 10; i++)
		vector.push_back(i);
	try
	{
		std::vector<int>::iterator it_vector = easyfind(vector, 4);
		std::cout << *it_vector << std::endl;
		std::vector<int>::iterator it_vector_error  = easyfind(vector, 11);
		std::cout << *it_vector_error << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i <= 10; i++)
		list.push_back(i);
	try
	{
		std::list<int>::iterator it_list = easyfind(list, 6);
		std::cout << *it_list << std::endl;
		std::list<int>::iterator it_list_error  = easyfind(list, 11);
		std::cout << *it_list_error  << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}