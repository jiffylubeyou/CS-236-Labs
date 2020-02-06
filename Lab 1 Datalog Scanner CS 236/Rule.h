#ifndef RULE_H
#define RULE_H
#include <vector>
#include <sstream>
#include "Predicate.h"

using namespace std;

class Rule
{
public:
	Rule();
	~Rule();

	void setHeadPredicate(Predicate headPredicate)
	{
		this->headPredicate = headPredicate;
	}

	Predicate getHeadPredicate()
	{
		return headPredicate;
	}

	void addPredicates(Predicate predicate)
	{
		predicates.push_back(predicate);
	}

	void clearPredicates()
	{
		predicates.clear();
	}

	string toString()
	{
		ostringstream out;
		out << headPredicate.toString();
		out << " :- ";
		for (unsigned int i = 0; i < predicates.size(); i++)
		{
			out << predicates.at(i).toString();
			if (i != predicates.size() - 1)
			{
				out << ",";
			}
		}
		return out.str();
	}
protected:
	Predicate headPredicate;
	vector<Predicate> predicates;
};
#endif

