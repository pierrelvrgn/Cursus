#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


int main()
{
	Bureaucrat test1("test1", 4);
	Bureaucrat test2("test2", 44);
	Bureaucrat test3("test3", 150);
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	ShrubberyCreationForm shrubbery("jardin");
	PresidentialPardonForm pardon("testttttttttt");
	RobotomyRequestForm robotomy("mr robot");
	test1.executeForm(pardon);
	test2.executeForm(robotomy);
	test3.executeForm(shrubbery);
	std::cout << std::endl;
	test1.signForm(pardon);
	test2.signForm(robotomy);
	test3.signForm(shrubbery);
	std::cout << std::endl;
	test1.executeForm(pardon);
	test2.executeForm(robotomy);
	test3.executeForm(shrubbery);
	std::cout << std::endl;
}
