#include "Form.hpp"

Form::Form()
: _name("Random Form"), _isSign(false), _gradeForSign(50), _gradeForExecute(25)
{
	std::cout << "Random Form: Form constructor" << std::endl;
}

Form::Form( const std::string name, const int gradeForSign, const int gradeForExecute, bool isSign)
: _name(name), _isSign(isSign), _gradeForSign(gradeForSign), _gradeForExecute(gradeForExecute)
{
	if (gradeForExecute < 1 || gradeForSign < 1)
		throw Form::GradeTooHighException();
	if (gradeForExecute > 150 || gradeForSign > 150)
		throw Form::GradeTooLowException();
	std::cout << _name << ": Form constructor" << std::endl;
}

Form::Form(const Form &C)
: _name(C._name), _isSign(C._isSign), _gradeForSign(C._gradeForSign), _gradeForExecute(C._gradeForExecute)
{
	std::cout << "Form constructor copy" << std::endl;
}

Form &Form::operator=(const Form &C)
{
	if (this == &C)
		return (*this);
	(int&)this->_gradeForExecute = const_cast<int&>(C._gradeForExecute);
	(int&)this->_gradeForSign = const_cast<int&>(C._gradeForSign);
	this->_isSign = C._isSign;
	(std::string&)this->_name = const_cast<std::string&>(C._name);
	std::cout << "Form operator = " << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Form& C)
{
	if (C.getIsSign() == true)
		out << C.getName() << "is sign. His grade for sign is : " << C.getGradeForSign() << ". His grade for execute is : " << C.getGradeForExecute();
	else
		out << C.getName() << "isn't sign. His grade for sign is : " << C.getGradeForSign() << ". His grade for execute is : " << C.getGradeForExecute();
	return (out);
}

bool	Form::getIsSign() const
{
	return this->_isSign;
}

int	Form::getGradeForSign() const
{
	return this->_gradeForSign;
}

int	Form::getGradeForExecute() const
{
	return this->_gradeForExecute;
}

std::string	Form::getName() const
{
	return this->_name;
}

void Form::beSigned(Bureaucrat &C)
{
	if (C.getGrade() > this->_gradeForSign)
		throw Form::GradeTooLowException();
	this->_isSign = true;
}

