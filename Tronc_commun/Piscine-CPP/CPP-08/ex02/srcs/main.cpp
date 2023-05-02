#include <iostream>
#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(8);
		mstack.push(59);
		std::cout << *mstack.begin() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(12);
		mstack.push(56);
		mstack.push(7);
		MutantStack<int>::iterator iterator_begin = mstack.begin();
		MutantStack<int>::iterator iterator_end = mstack.end();
		while (iterator_begin != iterator_end)
		{
			std::cout << *iterator_begin << std::endl;
			++iterator_begin;
		}
	}

	std::cout << "==============================================================" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(8);
		lst.push_back(59);
		std::cout << *lst.begin() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(12);
		lst.push_back(56);
		lst.push_back(7);
		std::list<int>::iterator iterator_begin = lst.begin();
		std::list<int>::iterator iterator_end = lst.end();
		while (iterator_begin != iterator_end)
		{
			std::cout << *iterator_begin << std::endl;
			++iterator_begin;
		}
		return 0;
	}
}
