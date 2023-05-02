#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
: _count(0), _index(0)
{
}

PhoneBook::~PhoneBook()
{
	return;
}

Contact PhoneBook::getContact(int index) const
{
	return this->_contact[index];
}

int	PhoneBook::getCount() const
{
	return this->_count;
}

void PhoneBook::setContact(Contact contact)
{
	this->_contact[this->_index] = contact;
	if (_count < 8)
		_count++;
	this->_index = (this->_index + 1) % 8;
	return;
}

void view_contact(std::string str)
{
	std::cout << "│" << std::setw(10) << std::right << str;
}

void PhoneBook::searchContact() const
{
	int index;
	int count;

	count = getCount();
	view_contact("index");
	view_contact("first name");
	view_contact("last name");
	view_contact("nickname");
	std::cout << "|" << std::endl;
	for (int i=0; i < getCount(); i++)
	{
		Contact contact;
		contact = getContact(i);
		view_contact(std::to_string(i + 1));
		view_contact(ft_truncate(contact.getFirstName()));
		view_contact(ft_truncate(contact.getLastName()));
		view_contact(ft_truncate(contact.getNickName()));
		std::cout << "|" << std::endl;
	}
	if (count > 0)
	{
		std::cout << "Please enter an index for more information: ";
		while (!(std::cin >> index) || index > count || index < 1)
		{
			if (std::cin.eof())
				exit(0);
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index ! Please enter an index between 1 and " << count << ": ";
		}
		index--;
		Contact tmp;
		tmp = getContact(index);
		std::cout << std::endl;
		std::cout << "First name - " << tmp.getFirstName() << std::endl;
		std::cout << "Last name - " << tmp.getLastName() << std::endl;
		std::cout << "Nickname - " << tmp.getNickName() << std::endl;
		std::cout << "Phone number - " << tmp.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret - " << tmp.getSecret() << std::endl;
	}
	else
	{
		std::cout << "PhoneBook is empty!" << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return;
}

void PhoneBook::addContact()
{
	Contact 	contact;
	std::string str;

	std::cout << "First name: ";
	contact.setFirstName(ft_getline(0));
	std::cout << "Last name: ";
	contact.setLastName(ft_getline(0));
	std::cout << "Nickname: ";
	contact.setNickName(ft_getline(0));
	std::cout << "Phone number: ";
	contact.setPhoneNumber(ft_getline(1));
	std::cout << "Darkest secret: ";
	contact.setSecret(ft_getline(0));
	setContact(contact);
}
