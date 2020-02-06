#ifndef PREDICATE_H
#define PREDICATE_H
#include <vector>
#include <sstream>
#include "Parameter.h"

using namespace std;

class Predicate
{
public:
	Predicate();
	~Predicate();

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	void addParameters(Parameter parameter)
	{
		parameters.push_back(parameter);
	}

	void clearParameters()
	{
		parameters.clear();
	}

	vector<Parameter> getParameters()
	{
		return parameters;
	}

	string toString()
	{
		ostringstream out;
		out << name << "(";
		for (unsigned int i = 0; i < parameters.size(); i++)
		{
			out << parameters.at(i).getValue();
			if (i != parameters.size() - 1)
			{
				out << ",";
			}
		}
		out << ")";
		return out.str();
	}

protected:
	string name;
	vector<Parameter> parameters;
};
#endif

