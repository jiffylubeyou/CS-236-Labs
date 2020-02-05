#pragma once
#include <vector>

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

