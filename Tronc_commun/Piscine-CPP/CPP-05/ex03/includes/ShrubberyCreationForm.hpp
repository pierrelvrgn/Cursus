#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& C);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& C);
		~ShrubberyCreationForm();
		void action(const Bureaucrat& C) const;
	private:
		ShrubberyCreationForm();
};
