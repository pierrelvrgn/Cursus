#include <string>
#include "Form.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& C);
	~Intern();
	Intern& operator=(const Intern& C);
	class InvalidFormException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("invalid form type");
			}
	};
	Form* makeForm(const std::string& formName, const std::string& target) const;
};
