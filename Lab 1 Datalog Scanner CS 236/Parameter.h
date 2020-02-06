#ifndef PARAMETER_H
#define PARAMETER_H
#include <vector>
#include <string>

using namespace std;

class Parameter
{
public:
	Parameter();
	~Parameter();

	void setValue(string myValue)
	{
		this->myValue = myValue;
	}

	string getValue()
	{
		return myValue;
	}
protected:
	string myValue;
};
#endif

