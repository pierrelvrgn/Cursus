#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(const std::string& name)
	: _name(name), _target(""), _signed(false), _gradeSign(75), _gradeExec(50)
{
	std::cout << "Basic Form constructor" << std::endl;
}

Form::Form(const std::string& name, const std::string& target)
	: _name(name), _target(target), _signed(false), _gradeSign(75), _gradeExec(50)
{
	std::cout << "Target Form constructor" << std::endl;
}

Form::Form(const std::string& name, const int gradeSign, const int gradeExec)
	: _name(name), _target(""), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "More Form constructor" << std::endl;
}

Form::Form(const std::string& name, const std::string& target, const int gradeSign, const int gradeExec)
	: _name(name), _target(target), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Full Form constructor" << std::endl;
}

Form::Form(const Form& C)
	: _name(C._name), _signed(C._signed), _gradeSign(C._gradeSign), _gradeExec(C._gradeExec)
{
	std::cout << "Copy Form constructor" << std::endl;
}

Form& Form::operator=(const Form& C)
{
	if (this == &C)
		return (*this);
	(int&)this->_gradeExec = const_cast<int&>(C._gradeExec);
	(int&)this->_gradeSign = const_cast<int&>(C._gradeSign);
	this->_signed = C._signed;
	(std::string&)this->_name = const_cast<std::string&>(C._name);
	(std::string&)this->_target = const_cast<std::string&>(C._target);
	std::cout << "Form operator = " << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

int Form::getGradeForSign() const
{
	return this->_gradeSign;
}

int Form::getGradeForExecute() const
{
	return this->_gradeExec;
}

std::string Form::getName() const
{
	return this->_name;
}

std::string Form::getTarget() const
{
	return this->_target;
}

bool Form::getIsSign() const
{
	return this->_signed;
}

void Form::beSigned(const Bureaucrat& C)
{
	if (!this->_signed)
	{
		if (C.getGrade() <= this->_gradeSign)
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
	else
		throw Form::FormAlreadySignedException();
}

void Form::execute(const Bureaucrat& C) const
{
	if (!this->getIsSign())
		throw Form::FormNotSignedException();
	if (C.getGrade() > this->getGradeForExecute())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const Form& C)
{
	if (C.getIsSign() == true)
		out << C.getName() << "is sign. His grade for sign is : " << C.getGradeForSign() << ". His grade for execute is : " << C.getGradeForExecute()<< ". His target is : " << C.getTarget();
	else
		out << C.getName() << "isn't sign. His grade for sign is : " << C.getGradeForSign() << ". His grade for execute is : " << C.getGradeForExecute()<< ". His target is : " << C.getTarget();
	return (out);
}
