#ifndef DATABASE_H
#define DATABASE_H
#include "Relation.h"

#include <map>
#include <sstream>

using namespace std;

class Database : map<string, Relation>
{
public:
	Database();
	~Database();

	void addRelation(string name, Relation relation)
	{
		relationMap.insert(pair<string, Relation>(name, relation));
	}

	Relation returnRelation(string string)
	{
		return this->relationMap.find(string)->second;
	}

	string toString()
	{
		ostringstream out;
		for (pair<string, Relation> element : relationMap)
		{
			out << element.first << endl;
			out << element.second.toString() << endl;
		}
		return out.str();
	}
private:
	map<string, Relation> relationMap;
};

#endif