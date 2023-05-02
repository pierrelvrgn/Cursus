#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat &C)
{
	this->_grade = C._grade;
	this->_name = C._name;
	std::cout << "Bureaucrat constructor copy" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &C)
{
	this->_grade = C._grade;
	this->_name = C._name;
	return *this;
	std::cout << "Bureaucrat operator" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}


void Bureaucrat::increaseGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = _grade - 1;
	std::cout << this->_name << ": Bureaucrat increaseGrade" << std::endl;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = _grade + 1;
	std::cout << this->_name << ": Bureaucrat decreaseGrade" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& C)
{
	out << C.getName() << ", bureaucrat grade " << C.getGrade();
	return (out);
}

void	Bureaucrat::signForm(Form &C)
{
	if (this->_grade > C.getGradeForSign())
		std::cout << this->_name << " couldn’t sign " << C.getName() << " because his grade is too low." << std::endl;
	else if (C.getIsSign() == true)
		std::cout << this->_name << " signed " << C.getName() << std::endl;
	else
		std::cout << this->_name << " couldn’t sign " << C.getName() << " because he didn't try." << std::endl;
}
