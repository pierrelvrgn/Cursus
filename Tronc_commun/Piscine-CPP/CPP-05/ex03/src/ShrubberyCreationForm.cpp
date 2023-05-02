#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("shrubbery", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->Form::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("shrubbery", "default", 145, 137)
{
}

void ShrubberyCreationForm::action(const Bureaucrat& executor) const
{
	this->Form::execute(executor);
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	if (!ofs.is_open())
		throw std::ofstream::failure(strerror(errno));
	ofs <<"           *    *  *" << std::endl;
	ofs <<"      *  *    *     *  *" << std::endl;
	ofs <<"              * *" << std::endl;
	ofs <<"     *     *    *  *    *" << std::endl;
	ofs <<" * *   *    *    *    *   *" << std::endl;
	ofs <<" *     *  *    * * .#  *   *" << std::endl;
	ofs <<" *   *     * #.  .# *   *" << std::endl;
	ofs <<"  *     \"#.  #: #\" * *    *" << std::endl;
	ofs <<" *   * * \"#. ##\"       *" << std::endl;
	ofs <<"   *       \"###" << std::endl;
	ofs <<"             \"##" << std::endl;
	ofs <<"              ##." << std::endl;
	ofs <<"              .##:" << std::endl;
	ofs <<"              :###" << std::endl;
	ofs <<"              ;###" << std::endl;
	ofs <<"            ,####." << std::endl;
	ofs <<"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
}
