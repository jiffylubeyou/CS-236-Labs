#include "DatalogProgram.h"
#include <algorithm>


DatalogProgram::~DatalogProgram()
{
}

void DatalogProgram::datalogProgram()
{
	match("SCHEMES");
	match("COLON");
	scheme();
	schemeList();
	match("FACTS");
	match("COLON");
	factList();
	match("RULES");
	match("COLON");
	ruleList();
	match("QUERIES");
	match("COLON");
	query();
	queryList();
	toString();
	match("EOF");
}

void DatalogProgram::match(string typeID)
{
	if (tokens.at(i).getType() == typeID)
	{
		i++;
	}
	else
	{
		throw tokens.at(i);
	}
}

void DatalogProgram::scheme()
{
	Parameter newParameter;
	tempPredicate.setName(tokens.at(i).getValue());
	match("ID");
	match("LEFT_PAREN");
	newParameter.setValue(tokens.at(i).getValue());
	tempPredicate.addParameters(newParameter);
	match("ID");
	idList();
	match("RIGHT_PAREN");
	schemes.push_back(tempPredicate);
	tempPredicate.clearParameters();
}

void DatalogProgram::fact()
{
	Parameter newParameter;
	tempPredicate.setName(tokens.at(i).getValue());
	match("ID");
	match("LEFT_PAREN");
	newParameter.setValue(tokens.at(i).getValue());
	tempPredicate.addParameters(newParameter);
	match("STRING");
	stringList();
	match("RIGHT_PAREN");
	match("PERIOD");
	facts.push_back(tempPredicate);
	tempPredicate.clearParameters();
}

void DatalogProgram::rule()
{
	headPredicate();
	tempRule.setHeadPredicate(tempPredicate);
	tempPredicate.clearParameters();
	match("COLON_DASH");
	predicate();
	tempRule.addPredicates(tempPredicate);
	tempPredicate.clearParameters();
	predicateList();
	match("PERIOD");
	rules.push_back(tempRule);
	tempRule.clearPredicates();
}

void DatalogProgram::query()
{
	predicate();
	queries.push_back(tempPredicate);
	tempPredicate.clearParameters();
	match("Q_MARK");
}

void DatalogProgram::headPredicate()
{
	tempPredicate.setName(tokens.at(i).getValue());
	match("ID");
	match("LEFT_PAREN");
	Parameter newParameter;
	newParameter.setValue(tokens.at(i).getValue());
	tempPredicate.addParameters(newParameter);
	match("ID");
	idList();
	match("RIGHT_PAREN");
}

void DatalogProgram::predicate()
{
	tempPredicate.setName(tokens.at(i).getValue());
	match("ID");
	match("LEFT_PAREN");
	Parameter newParameter;
	parameter();
	newParameter.setValue(tempParameter);
	tempPredicate.addParameters(newParameter);
	tempParameter.clear();
	paramenterList();
	match("RIGHT_PAREN");
}

void DatalogProgram::predicateList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		predicate();
		tempRule.addPredicates(tempPredicate);
		tempPredicate.clearParameters();
		predicateList();
	}
}

void DatalogProgram::paramenterList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		Parameter newParameter;
		parameter();
		newParameter.setValue(tempParameter);
		tempPredicate.addParameters(newParameter);
		tempParameter.clear();
		paramenterList();
	}
}

void DatalogProgram::stringList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		Parameter newParameter;
		newParameter.setValue(tokens.at(i).getValue());
		tempPredicate.addParameters(newParameter);
		match("STRING");
		stringList();
	}
}

void DatalogProgram::idList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		Parameter newParameter;
		newParameter.setValue(tokens.at(i).getValue());
		tempPredicate.addParameters(newParameter);
		match("ID");
		idList();
	}
}

void DatalogProgram::parameter()
{
	if (tokens.at(i).getType() == "STRING")
	{
		tempParameter = tempParameter + tokens.at(i).getValue();
		match("STRING");
	}
	else if (tokens.at(i).getType() == "ID")
	{
		tempParameter = tempParameter + tokens.at(i).getValue();
		match("ID");
	}
	else
	{
		expression();
	}
}

void DatalogProgram::expression()
{
	match("LEFT_PAREN");
	tempParameter = "(" + tempParameter;
	parameter();
	operatorasdf();
	parameter();
	tempParameter = tempParameter + ")";
	match("RIGHT_PAREN");
}

void DatalogProgram::operatorasdf()
{
	if (tokens.at(i).getType() == "ADD")
	{
		tempParameter = tempParameter + tokens.at(i).getValue();
		match("ADD");
	}
	else
	{
		tempParameter = tempParameter + tokens.at(i).getValue();
		match("MULTIPLY");
	}
}

void DatalogProgram::schemeList()
{
	if (tokens.at(i).getType() == "ID")
	{
		scheme();
		schemeList();
	}
	else
	{
		;
	}
}

void DatalogProgram::factList()
{
	if (tokens.at(i).getType() == "ID")
	{
		fact();
		factList();
	}
	else
	{
		;
	}
}

void DatalogProgram::ruleList()
{
	if (tokens.at(i).getType() == "ID")
	{
		rule();
		ruleList();
	}
	else
	{
		;
	}
}

void DatalogProgram::queryList()
{
	if (tokens.at(i).getType() == "ID")
	{
		query();
		queryList();
	}
}

string DatalogProgram::toString()
{
	ostringstream out;
	out << "Success!" << endl;
	out << "Schemes(" << schemes.size() << "):" << endl;
	for (int j = 0; j < schemes.size(); ++j)
	{
		out << "  " << schemes.at(j).toString() << endl;
	}

	out << "Facts(" << facts.size() << "):" << endl;
	for (int j = 0; j < facts.size(); ++j)
	{
		out << "  " << facts.at(j).toString() << "." << endl;
	}

	out << "Rules(" << rules.size() << "):" << endl;
	for (int j = 0; j < rules.size(); ++j)
	{
		out << "  " << rules.at(j).toString() << "." << endl;
	}

	out << "Queries(" << queries.size() << "):" << endl;
	for (int j = 0; j < queries.size(); ++j)
	{
		out << "  " << queries.at(j).toString() << "?" << endl;
	}

	//filter out the repeats
	vector<string> domains;
	for (int j = 0; j < facts.size(); ++j)
	{
		vector<Parameter> tempParameterVector = facts.at(j).getParameters();
		for (int k = 0; k < tempParameterVector.size(); ++k)
		{
			if (domains.size() == 0)
			{
				domains.push_back(tempParameterVector.at(k).getValue());
			}
			else {
				bool matched = false;
				for (int l = 0; l < domains.size(); ++l)
				{
					if (tempParameterVector.at(k).getValue() == domains.at(l))
					{
						matched = true;
					}
				}
				if (!matched)
				{
					domains.push_back(tempParameterVector.at(k).getValue());
				}
			}
		}
	}
	sort(domains.begin(), domains.end());
	out << "Domain(" << domains.size() << "):" << endl;
	for (int j = 0; j < domains.size(); ++j)
	{
		out << "  " << domains.at(j) << endl;
	}

	return out.str();
}