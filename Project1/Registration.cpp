#include "Registration.h"

void Registration::setPassword(const string& password)
{
	if (password == " ")
		throw InvalidPassword("Error with set-name!!!");
	password_ = password;
}

void Registration::setLogin(const string& login)
{
	if (login == " ")
		throw InvalidLogin("Error with set-login!!!");
	
	login_ = login;
}

void Registration::print() const
{
	cout << "~~~WORKED REGISTRATION PRINT~~~" << endl;
	cout << "Login user:\t" << login_ << endl;
	cout << "Password user:\t" << password_ << endl;
	cout << endl;
}

const string& Registration::getLogin() const
{
	return login_;
}

const string& Registration::getPassword() const
{
	return password_;
}

const string& Exception::what() const
{
	return errMessage;
}

void SocialNetwork::registr(string login, string pass) 
{
	try
	{
		Registration reg(login,pass);
		for (auto& i : accounts)
		{
			i.getLogin() == login; throw isUserAlredy("Login is busy!!!");
		}
	}
	catch (const std::exception& e) 
	{
		cout << e.what() << endl;
	}
}
