#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
std::string	ft_getline(int nb);
std::string ft_truncate(std::string str);

class Contact
{
	public:

		Contact();
		~Contact();
		void		setFirstName(std::string first_name);
		void		setLastName(std::string last_name);
		void		setNickName(std::string nick_name);
		void		setPhoneNumber(std::string number);
		void		setSecret(std::string secret);
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getSecret();

	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_secret;
};
