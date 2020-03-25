#include "Relation.h"


Relation::~Relation()
{
}

Relation Relation::join(Relation relation)
{
	//gets newRelation scheme
	Predicate tempPredicate = this->scheme;
	vector<int> tupleIndices;
	for (unsigned int i = 0; i < relation.getScheme().size(); ++i)
	{
		bool isFound = false;
		for (unsigned int j = 0; j < this->scheme.size(); ++j)
		{
			if (this->scheme.at(j) == relation.getScheme().at(i))
			{
				isFound = true;
			}
		}
		if (!isFound)
		{
			Parameter tempParameter;
			tempParameter.setValue(relation.getScheme().at(i));
			tempPredicate.addParameters(tempParameter);
			tupleIndices.push_back(i);
		}
	}
	Relation newRelation(this->name, tempPredicate);
	for (Tuple tuple : this->tuples)
	{
		for (Tuple secondTuple : relation.getTuples())
		{
			if (isJoinable(this->scheme, relation.getScheme(), tuple, secondTuple))
			{
				Tuple tempTuple = tuple;
				for (unsigned int i = 0; i < tupleIndices.size(); ++i)
				{
					tempTuple.push_back(secondTuple.at(i));
				}
				newRelation.addTuple(tempTuple);
			}
		}
	}
	return newRelation;
}

bool Relation::isJoinable(Predicate scheme1, Predicate scheme2, Tuple tuple1, Tuple tuple2)
{
	for (unsigned int i = 0; i < tuple1.size(); ++i)
	{
		for (unsigned int j = 0; j < tuple2.size(); ++j)
		{
			if ((scheme1.at(i) == scheme2.at(j)) && (tuple1.at(i) != tuple2.at(j)))
			{
				return false;
			}
		}
	}
	return true;
}
