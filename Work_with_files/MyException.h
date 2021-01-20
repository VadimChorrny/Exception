#pragma once
#include <string>
#include <iostream>
using namespace std;

class MyException
{
public:
	MyException(const string& errMessage = "Unknow error!") : errMessage{ errMessage }
	{

	}
private:
	string errMessage;
	virtual const string& what() const
	{
		return errMessage;
	}
};

class InvalidNameException : public MyException
{
public:
	InvalidNameException(const string& message = "Error name!") : MyException(message){}
	//const string& what() const override;

};
class InvalidSizeExeption : public MyException
{
public:
	InvalidSizeExeption(const double& errSize ,const string& errMessage="Error size!") : MyException(errMessage + "Error size:\t" + to_string(errSize)), errSize(errSize)
	{}
	const double& getErrSize() const
	{
		return errSize;
	}
private:
	double errSize;
};

class Room
{
public:
	Room(const char*name = "Noname", double width = 0, double length = 0)
	{
		try {
			setName(name);
			setWidth(width);
			setLength(length);
		}
		catch (const MyException& ex)
		{
			this->~Room();
			throw; // перевикидання вийнятку
			
		}


	}
	~Room();

	void setName(const char* name);
	void setWidth(const double& width);
	void setLength(const double& length);
	void print() const;
private:
	char* name_;
	double width_, length_;
};
