#ifndef RELATION_H
#define RELATION_H

#include <set>
#include<sstream>

#include"Tuple.h"
#include"Scheme.h"

using namespace std;

class Relation
{
public:
	Relation(string name, Scheme scheme) { this->name = name; this->scheme = scheme; };
	~Relation();

	void addTuple(Tuple tuple)
	{
		tuples.insert(tuple);
	}

	string toString()
	{
		ostringstream out;
		for (Tuple tuple : tuples) {
			for (unsigned int i = 0; i < tuple.size() - 1; ++i)
			{
				out << scheme.at(i) << "='" << tuple.at(i);
				if (i != tuple.size() - 1)
				{
					out << ",";
				}
				out << endl;
			}
		}
		return out.str();
	}
private:
	Scheme scheme;
	set<Tuple> tuples;
	string name;
};
#endif