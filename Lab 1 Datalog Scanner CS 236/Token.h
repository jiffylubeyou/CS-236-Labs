#pragma once
#include <iostream>
#include <sstream>
#include <sstream>

using namespace std;

class Token
{
public:
	Token();
	~Token();

	void setType(string type)
	{
		this->type = type;
	}
	string getType()
	{
		return type;
	}
	void setValue(string value)
	{
		this->value = value;
	}
	string getValue()
	{
		return value;
	}
	void setLineVal(int lineNum)
	{
		this->lineNum = lineNum;
	}
	int getLineVal()
	{
		return lineNum;
	}

	string toString()
	{
		ostringstream out;
		out << "(" << getType() << ",\"" << getValue() << "\"," << getLineVal() << ")" << endl;
		return out.str();
	}
protected:
	string type;
	string value;
	int lineNum;
};

