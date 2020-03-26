
#include "Interpreter.h"

Interpreter::~Interpreter()
{
}

void Interpreter::populateInterpreter()
{
	schemes = datalogProgram.getSchemes();
	facts = datalogProgram.getFacts();
	rules = datalogProgram.getRules();
	queries = datalogProgram.getQueries();
	return;
}

void Interpreter::populateDatabase()
{
	for (unsigned int i = 0; i < schemes.size(); ++i)
	{
		Relation tempRelation(schemes.at(i).getName(), schemes.at(i));
		for (unsigned int j = 0; j < facts.size(); ++j)
		{
			if (facts.at(j).getName() == schemes.at(i).getName())
			{
				Tuple tempTuple;
				for (unsigned int k = 0; k < facts.at(j).size(); ++k)
				{
					tempTuple.push_back(facts.at(j).at(k));
				}
				tempRelation.addTuple(tempTuple);
			}
		}
		database.addRelation(schemes.at(i).getName(), tempRelation);
	}
}

Relation Interpreter::EvaluateQuery(Predicate query)
{
	vector<int> projectVector;
	Predicate tempPredicate;
	unordered_map<string, int> tempMap;
	Relation tempRelation(database.returnRelation(query.getName()));
	for (unsigned int i = 0; i < query.size(); ++i)
	{
		if (query.at(i)[0] == '\'')
		{
			tempRelation = tempRelation.select(query.at(i), i);
		}
		else
		{
			if (tempMap.count(query.at(i)) == 1)
			{
				tempRelation = tempRelation.select(i, tempMap.at(query.at(i)));	
			}
			else
			{
				tempMap[query.at(i)] = i;
				projectVector.push_back(i);
				Parameter tempParameter;
				tempParameter.setValue(query.at(i));
				tempPredicate.addParameters(tempParameter);
			}
		}
	}
	tempRelation = tempRelation.project(projectVector);
	tempRelation = tempRelation.rename(tempPredicate);
	return tempRelation;
}

void Interpreter::EvaluateRule(Rule rule)
{
	vector<Relation> relations;
	vector<Predicate> predicates = rule.getPredicates();
	for (unsigned int i = 0; i < rule.getPredicates().size(); ++i)
	{
		relations.push_back(EvaluateQuery(predicates.at(i)));
	}
	Relation tempRelation = relations.at(0);
	for (unsigned int i = 1; i < relations.size(); ++i)
	{
		tempRelation = tempRelation.join(relations.at(i));
	}
	tempRelation = tempRelation.projectHeadPredicate(rule.getHeadPredicate());
	tempRelation = tempRelation.rename(database.returnRelation(rule.getHeadPredicate().getName()).getScheme());
	for (Tuple tuple : tempRelation.getTuples())
	{
		database.addTupleToRelation(rule.getHeadPredicate().getName(), tuple);
	}
}

void Interpreter::EvaluateRules()
{
	unsigned int oldTotal = 0;
	unsigned int newTotal = 0;
	bool change = true;
	while (change)
	{
		oldTotal = database.getNumDatabaseTuples();
		for (unsigned int i = 0; i < rules.size(); ++i)
		{
			EvaluateRule(rules.at(i));
		}
		newTotal = database.getNumDatabaseTuples();
		if (newTotal == oldTotal)
		{
			change = false;
		}
	}
	return;
}


string Interpreter::EvaluateAll()
{
	EvaluateRules();
	ostringstream out;
	for (unsigned int i = 0; i < queries.size(); ++i)
	{
		out << queries.at(i).toString() << "? ";
		Relation tempRelation = EvaluateQuery(queries.at(i));
		if (tempRelation.getNumTuples() == 0)
		{
			out << "No" << endl;
		}
		else
		{
			out << "Yes(" << tempRelation.getNumTuples() << ")" << endl;
			out << tempRelation.toString();
		}
	}
	return out.str();
}
