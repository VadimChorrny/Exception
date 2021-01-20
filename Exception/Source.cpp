#include <iostream>
using namespace std;

template <typename T>
class BadArgument : public invalid_argument
{
public:
	BadArgument(const T& value, const string& message="Bad value")
		: invalid_argument(message), errValue(value)
	{}
	const T& getBadValue() const
	{
		return errValue;
	}
private:
	T errValue;
};

void funcDemo(double value)
{
	if (value < 0)
		throw BadArgument<double>(value, "Negative value!");
	else
		value++;
	cout << "DEMO WORKED!" << value << endl;
}

int main()
{
	try
	{
		funcDemo(10.5);
		funcDemo(-1.4);
	}
	catch (const BadArgument<double>& ex)
	{
		cout << ex.what() << endl;
	}
	catch(const exception& ex)
	{ 
	/*	using myType = BadArgument<double>&;
		cout << ex.what() << endl;
		auto m = reinterpret_cast<myType&>(ex);*/

	}
}