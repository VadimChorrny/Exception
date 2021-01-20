
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Exception
{
public:
	Exception(const string& errMessage = "Unknow error!") : errMessage{ errMessage }{}
	virtual const string& what() const;
private:
	string errMessage;
};

class InvalidPassword : public Exception
{
public:
	InvalidPassword(const string& message = "Error with pass!!!") : Exception(message){}
};

class InvalidLogin : public Exception
{
public:
	InvalidLogin(const string& message = "Error with login!!!") : Exception(message){}
};

class isUserAlredy : public Exception
{
public:
	isUserAlredy(const string& message = "User is already") : Exception(message){}
};


class Registration
{
public:
	Registration(const string& login, const string& password) 
	{
		setPassword(password);
		setLogin(login);
	}
	void setPassword(const string& password);
	void setLogin(const string& login);
	void print() const;

	// get

	const string& getLogin() const;
	const string& getPassword() const;
private:
	string password_;
	string login_;
};

class SocialNetwork : public Registration
{
public:
	SocialNetwork(const string& login, const string& password) : Registration(login,password){}
	void registr(string login, string pass);
private:
	vector<Registration> accounts;
};
