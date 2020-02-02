#include <iostream>
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

	//string toString(Token token, int lineNum);

protected:
	string type;
	string value;
};

