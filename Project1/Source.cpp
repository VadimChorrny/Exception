#include <iostream>
#include "Registration.h"
using namespace std;



int main()
{

	try
	{
		SocialNetwork soc("Chorrny", "1234");
		soc.registr("Chorrny", "1234");
		soc.print();
	}
	catch (InvalidLogin& ex)
	{
		cout << ex.what() << endl;
	}
	catch (InvalidPassword& ex)
	{
		cout << ex.what() << endl;
	}
	catch (isUserAlredy& ex)
	{
		cout << ex.what() << endl;
	}
}