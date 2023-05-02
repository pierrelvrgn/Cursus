#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("robotomy", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& C)
	: Form(C)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& C)
{
	this->Form::operator=(C);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm()
	: Form("robotomy", "default", 72, 45)
{
}

void RobotomyRequestForm::action(const Bureaucrat& C) const
{
	this->Form::execute(C);
	std::cout << "Makes some drilling noises" << std::endl;
	if ((rand() % 2 + 1) % 2 == 1)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed." << std::endl;
}
