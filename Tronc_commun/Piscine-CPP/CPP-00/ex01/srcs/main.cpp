#include "../includes/PhoneBook.hpp"

std::string	ft_getline(int nb)
{
	std::string str("");
	while (str == "")
	{
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit(0);
		if (str == "")
			std::cout << "ERROR : Please enter a value : ";
		if (nb == 1 && str != "")
		{
			for (int i = 0; i < (int)(str.size()); i++)
			{
				if (!std::isdigit(str[i]))
				{
					std::cout << "ERROR : Please enter a number : ";
					i = (int)(str.size()) + 1;
					str = "";
				}
			}
		}
	}
	return (str);
}

std::string	ft_truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int main()
{
	PhoneBook phonebook;

	std::cout << "Try ADD, SEARCH or EXIT ..." << std::endl;
	while (1)
	{
		std::string command;
		std::cout << std::endl << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(0);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Wrong command ! Try again ..." << std::endl;
	}
}
