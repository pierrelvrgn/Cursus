#pragma once
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &C);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &C);
		~Bureaucrat();
		void		increaseGrade();
		void		decreaseGrade();
		int	getGrade() const ;
		std::string	getName() const ;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade Too High");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade Too Low");
				}
		};
	private:
		std::string _name;
		int _grade;
};

std::ostream	&operator<<(std::ostream& out, const Bureaucrat& C);
