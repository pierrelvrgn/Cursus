#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form &C);
		Form( const std::string _name, const int _gradeForSign, const int _gradeForExecute, bool isSign);
		Form &operator=(const Form &C);
		~Form();
		bool	getIsSign() const ;
		int	getGradeForSign() const ;
		int	getGradeForExecute() const ;
		std::string	getName() const ;
		void beSigned(Bureaucrat &C);
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
	private :
		const std::string _name;
		bool _isSign;
		const int _gradeForSign;
		const int _gradeForExecute;
};

std::ostream	&operator<<(std::ostream& out, const Form& C);
