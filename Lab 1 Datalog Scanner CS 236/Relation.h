#ifndef RELATION_H
#define RELATION_H

#include <set>
#include<sstream>

#include"Tuple.h"
#include"Scheme.h"
#include"Predicate.h"

using namespace std;

class Relation
{
public:
	Relation(string name, Predicate scheme) { this->name = name; this->scheme = scheme; };
	~Relation();

	void addTuple(Tuple tuple)
	{
		tuples.insert(tuple);
	}

	string addRuleTuple(Tuple tuple)
	{
		ostringstream out;
		if (tuples.insert(tuple).second)
		{
			tuples.insert(tuple);
			out << " ";
			for (unsigned int i = 0; i < this->scheme.size(); ++i)
			{
				out << " " << this->scheme.at(i) << "=" << tuple.at(i);
				if (i != tuple.size() - 1)
				{
					out << ",";
				}
			}
			if (tuple.size() != 0)
			{
				out << endl;
			}
			else
			{
				return "";
			}
		}
		return out.str();
	}

	Relation select(string value, int index)
	{
		Relation tempRelation(this->name, this->scheme);
		for (Tuple tuple : tuples)
		{
			if (tuple.at(index) == value)
			{
				tempRelation.addTuple(tuple);
			}
		}
		return tempRelation;
	}

	Relation select(int index1, int index2)
	{
		Relation tempRelation(this->name, this->scheme);
		for (Tuple tuple : tuples)
		{
			if (tuple.at(index1) == tuple.at(index2))
			{
				tempRelation.addTuple(tuple);
			}
		}
		return tempRelation;
	}

	Relation project(vector<int> toKeep)
	{
		Relation tempRelation(this->name, this->scheme);
		for (Tuple tuple : tuples)
		{
			Tuple tempTuple;
			for (unsigned int i = 0; i < toKeep.size(); ++i)
			{
				tempTuple.push_back(tuple.at(toKeep.at(i)));
			}
			tempRelation.addTuple(tempTuple);
		}
		return tempRelation;
	}

	Relation projectHeadPredicate(Predicate predicate);

	Relation rename(Predicate predicate)
	{
		Relation tempRelation(name, predicate);
		tempRelation.tuples = this->tuples;
		return tempRelation;
	}

	Predicate getScheme() { return this->scheme; }
	set<Tuple> getTuples() { return tuples; }

	int getNumTuples()
	{
		return tuples.size();
	}

	string toString()
	{
		ostringstream out;
		for (Tuple tuple : tuples) {
			out << " ";
			for (unsigned int i = 0; i < scheme.size(); ++i)
			{
				out << " " << scheme.at(i) << "=" << tuple.at(i);
				if (i != tuple.size() - 1)
				{
					out << ",";
				}
			}
			if (tuple.size() != 0)
			{
				out << endl;
			}
			else
			{
				return "";
			}
		}
		return out.str();
	}

	Relation join(Relation relation);
	bool isJoinable(Predicate scheme1, Predicate scheme2, Tuple tuple1, Tuple tuple2);

private:
	Predicate scheme;
	set<Tuple> tuples;
	string name;
};
#endif