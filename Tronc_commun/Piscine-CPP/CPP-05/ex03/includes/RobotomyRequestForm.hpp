#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& C);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& C);
		~RobotomyRequestForm();
		void action(const Bureaucrat& C) const;
	private:
		RobotomyRequestForm();
};
