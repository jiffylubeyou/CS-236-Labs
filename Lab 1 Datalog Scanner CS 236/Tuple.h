#ifndef TUPLE_H
#define TUPLE_H
#include "DatalogProgram.h"

#include<sstream>

class Tuple : vector<string>
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