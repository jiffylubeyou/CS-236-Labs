#include "Relation.h"


Relation::~Relation()
{
}

Relation Relation::join(Relation relation)
{
	//gets newRelation scheme
	Predicate tempPredicate = this->scheme;
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
		}
	}
	Relation newRelation(this->name, tempPredicate);
	return relation;
}
