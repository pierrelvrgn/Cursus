#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& C);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& C);
		~PresidentialPardonForm();
		void action(const Bureaucrat& C) const;
	private:
		PresidentialPardonForm();
};
