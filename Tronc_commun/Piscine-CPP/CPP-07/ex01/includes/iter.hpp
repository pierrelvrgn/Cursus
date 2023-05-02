#include <iostream>

template <typename T>
void iter(T* tab, size_t size, void (*f)(const T&))
{
	for (size_t i = 0; i < size; i++)
		(*f)(tab[i]);
}

template <typename T>
void T_cout(const T& test)
{
	std::cout << test << std::endl;
}
