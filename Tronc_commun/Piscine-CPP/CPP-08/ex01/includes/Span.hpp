#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <limits>


class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(const Span &C);
		Span & operator = (const Span &C);
		void addNumber(int nb);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
		class FullException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Array is full";
				}
		};
		class EmptyException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Array is empty";
				}
		};
		class OneNumberException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "There is just one number";
				}
		};
	private:
		unsigned int _size;
		std::vector<int> _vector;
};
