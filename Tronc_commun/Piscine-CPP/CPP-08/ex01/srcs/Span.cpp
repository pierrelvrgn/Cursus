#include "../includes/Span.hpp"

Span::Span(void): _size(0)
{}

Span::Span(unsigned int N): _size(N)
{}

Span::~Span(void)
{}

Span::Span(const Span &C)
{
	*this = C;
}

Span &Span::operator = (const Span &C)
{
	_size = C._size;
	_vector = C._vector;
	return *this;
}

void Span::addNumber(int nb)
{
	if (_vector.size() >= _size)
		throw FullException();
	_vector.push_back(nb);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it < end; it++)
	{
		if ( _vector.size() >= _size)
			throw FullException();
		_vector.push_back(*it);
	}
}

int Span::shortestSpan(void)
{
	if (_vector.size() == 1 )
		throw OneNumberException();
	else if (_vector.size() == 0 )
		throw EmptyException();
 	int min = std::numeric_limits<int>::max ();
	for (size_t i = 0; i < _vector.size (); i++)
	{
		for (size_t j = i + 1; j < _vector.size (); j++)
		{
			if (_vector[i] > _vector[j])
			{
				if ((_vector[i] - _vector[j]) < min)
					min = (_vector[i] - _vector[j]);
			}
			else
				if (_vector[j] - _vector[i] < min)
					min = _vector[j] - _vector[i];
		}
	}
	return min;

}

int Span::longestSpan(void)
{
	if (_vector.size() < 2)
		throw OneNumberException();
	return *std::max_element (_vector.begin (), _vector.end ()) - *std::min_element (_vector.begin (), _vector.end ());
}
