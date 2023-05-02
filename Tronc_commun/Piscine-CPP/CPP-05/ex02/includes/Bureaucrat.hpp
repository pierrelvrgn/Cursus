#pragma once
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& C);
		Bureaucrat& operator=(const Bureaucrat& C);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		void signForm(Form& C) const;
		void executeForm(Form& C) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
	private:
		std::string _name;
		int		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& C);
