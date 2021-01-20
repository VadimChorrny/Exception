#include "MyException.h"

Room::~Room()
{
	if (name_ != nullptr)
	{
		cout << "~~~Dtor for~~~" << name_ << endl;

		delete[] name_;
		name_ = nullptr;
	}
		
}

void Room::setName(const char* name)
{
	if (name == nullptr) 
	{
		throw InvalidNameException("Error name : nullptr");
	}
	if (name[0] == '0')
	{
		throw InvalidNameException("Error name : empty");

	}
	auto size = strlen(name) + 1;
	name_ = new char[size];
	strcpy_s(name_, size, name);
}

void Room::setWidth(const double& width)
{
	if (width < 0)
		throw InvalidSizeExeption(width,"Error width!");
	width_ = width;


}

void Room::setLength(const double& length)
{
	if (length <= 0)
		throw InvalidSizeExeption(length,"Error lengt");
	length_ = length;


}

void Room::print() const
{
	cout << "~~~WORKED ROOM PRINT~~~" << endl;
	cout << "Room:\t" << name_ << endl;
	cout << "Width:\t" << width_ << endl;
	cout << "Length:\t" << length_ << endl;
}

//const string& InvalidNameException::what() const
//{
//	return;
//	// TODO: вставьте здесь оператор return
//}
