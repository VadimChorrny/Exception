#include<iostream>
#include "MyException.h"
using namespace std;

int main()
{
	Room room("Kitchen", -1, 3);
	room.print();
	try 
	{
		room.setName("");

	}
	catch (const MyException& ex)
	{
	}
	catch (...)
	{

	}
	
}