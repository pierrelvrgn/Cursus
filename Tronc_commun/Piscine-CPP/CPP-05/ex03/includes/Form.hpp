#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name);
		Form(const std::string& name, const std::string& target);
		Form(const std::string& name, const int gradeSign, const int gradeExec);
		Form(const std::string& name, const std::string& target, const int gradeSign, const int gradeExec);
		Form(const Form& C);
		Form& operator=(const Form& C);
		~Form();
		int getGradeForSign() const;
		int getGradeForExecute() const;
		std::string getName() const;
		std::string getTarget() const;
		bool getIsSign() const;
		void beSigned(const Bureaucrat& C);
		void execute(const Bureaucrat& C) const;
		virtual void action(const Bureaucrat& C) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("grade is too low");
				}
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("form is already signed");
				}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("form is not signed");
				}
		};
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int	_gradeSign;
		const int	_gradeExec;
};

std::ostream& operator<<(std::ostream& out, const Form& C);
