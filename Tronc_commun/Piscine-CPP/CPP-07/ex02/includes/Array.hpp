#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	public:
		Array<T>() : _n(0), _array(new T[0]) {};
		Array<T>(unsigned int n) : _n(n), _array(new T[n]) {};
		Array<T>(const Array& C)
		{
			_n = C._n;
			_array = new T[C._n];
			for (unsigned int i = 0; i < C._n; i++)
				_array[i] = C._array[i];
		}
		~Array<T>()
		{
			delete [] _array;
		}
		Array<T> &operator=(const Array& C)
		{
			if (this != &C)
			{
				~Array();
				_n = C._n;
				_array = new T[C._n];
				for (unsigned int i = 0; i < C._n; i++)
					_array[i] = C._array[i];
			}
			return *this;
		}
		T& operator[](unsigned int index)
		{
			if (index >= _n)
				throw OverflowException();
			return _array[index];
		}
		unsigned int size()
		{
			return _n;
		}
		class OverflowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("overflow");
				}
		};
	private:
		unsigned int _n;
		T* _array;
};
