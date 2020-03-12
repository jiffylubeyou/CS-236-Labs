#ifndef TUPLE_H
#define TUPLE_H

#include<vector>
#include<sstream>

using namespace std;

class Tuple : public vector<string>
{
public:
	Tuple();
	~Tuple();

	string toString()
	{
		ostringstream out;
		for (unsigned int i = 0; i < size(); ++i)
		{
			out << at(i);
		}
	}
};

#endif