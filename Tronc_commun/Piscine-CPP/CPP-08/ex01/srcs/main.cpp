#include "../includes/Span.hpp"

int main(void)
{
	srand(time(NULL));
	std::cout << std::endl << "==============================================================" << std::endl<< "TEST #1" << std::endl << "==============================================================" << std::endl;
	try
	{
		Span a = Span(5);

		a.addNumber(5);
		a.addNumber(12);
		a.addNumber(40);
		a.addNumber(60);
		a.addNumber(2);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "==============================================================" << std::endl<< "TEST #2" << std::endl << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1);

		a.addNumber(5);
		a.addNumber(12);
		a.addNumber(40);
		a.addNumber(60);
		a.addNumber(2);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "==============================================================" << std::endl<< "TEST #3" << std::endl << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1);

		a.addNumber(6);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "==============================================================" << std::endl<< "TEST #4" << std::endl << "==============================================================" << std::endl;
	try
	{
		Span a = Span(10000);

		std::vector<int> b(10000);
		std::generate(b.begin(), b.end(), std::rand);

		a.addNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "==============================================================" << std::endl<< "TEST #5" << std::endl << "==============================================================" << std::endl;
	try
	{
		Span a = Span(5);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
