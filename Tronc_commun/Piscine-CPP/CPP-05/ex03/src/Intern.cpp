#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern::Intern(const Intern& C)
{
	*this = C;
}

Intern &Intern::operator=(const Intern& C)
{
	(void)C;
	return (*this);
}


Form* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i = 0;
	while (i < 3 && formNames[i] != formName)
		i++;
	Form* tmp = NULL;
	switch (i)
	{
		case 0:
			tmp = new ShrubberyCreationForm(target);
			break;
		case 1:
			tmp = new RobotomyRequestForm(target);
			break;
		case 2:
			tmp = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::InvalidFormException();
	}
	std::cout << "Intern creates " << formName << std::endl;
	return tmp;
}
