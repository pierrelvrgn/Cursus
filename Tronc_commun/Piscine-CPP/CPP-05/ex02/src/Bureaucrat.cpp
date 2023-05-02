#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat()
: _name("Random bureaucrat"), _grade(75)
{
	std::cout << "Random Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << _name << " Bureaucrat constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}


std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::increaseGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	std::cout << this->_name << ": Bureaucrat increaseGrade" << std::endl;
}

void Bureaucrat::decreaseGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	std::cout << this->_name << ": Bureaucrat decreaseGrade" << std::endl;
}

void	Bureaucrat::signForm(Form &C) const
{
	try
	{
		C.beSigned(*this);
		std::cout << *this << " signed " << C.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << " cannot sign " << C.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form &C) const
{
	try
	{
		C.action(*this);
		std::cout << *this << " executed " << C.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << *this << " cannot execute " << C.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& C)
{
	out << C.getName() << ", bureaucrat grade " << C.getGrade();
	return out;
}
