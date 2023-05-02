#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: Form("pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& C)
: Form(C)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& C)
{
	this->Form::operator=(C);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm()
: Form("pardon", "default", 25, 5)
{
}

void PresidentialPardonForm::action(const Bureaucrat& C) const
{
	this->Form::execute(C);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
