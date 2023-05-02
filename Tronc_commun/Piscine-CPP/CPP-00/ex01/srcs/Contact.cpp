#include "../includes/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
	return;
}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickName()
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getSecret()
{
	return this->_secret;
}

void Contact::setFirstName(std::string first_name)
{
	this->_firstName = first_name;
	return;
}

void Contact::setLastName(std::string last_name)
{
	this->_lastName = last_name;
	return;
}

void Contact::setNickName(std::string nick_name)
{
	this->_nickName = nick_name;
	return;
}

void Contact::setPhoneNumber(std::string number)
{
	this->_phoneNumber = number;
	return;
}

void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
	return;
}
