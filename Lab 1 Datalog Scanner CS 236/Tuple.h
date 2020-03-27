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
		out << " ";
		for (unsigned int i = 0; i < size(); ++i)
		{
			out << at(i);
			if (i != this->size() - 1)
			{
				out << ",";
			}
		}
		return out.str();
	}
};

#endif