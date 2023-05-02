#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
std::string	ft_getline(int nb);
std::string ft_truncate(std::string str);

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();
		Contact		getContact(int index) const;
		int			getCount() const;
		void		setContact(Contact contact);
		void		searchContact() const;
		void		addContact();

	private:

		int		_count;
		Contact	_contact[8] ;
		int		_index;
};
