#include "DatalogProgram.h"


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
}

void DatalogProgram::match(string typeID)
{
	if (tokens.at(i).getType() == typeID)
		i++;
	else
		throw tokens.at(i);
}

void DatalogProgram::scheme()
{
	match("ID");
	Predicate newScheme;

	match("LEFT_PAREN");
	match("ID");
	idList();
	match("RIGHT_PAREN");
}

void DatalogProgram::fact()
{
	match("ID");
	match("LEFT_PAREN");
	match("STRING");
	stringList();
	match("RIGHT_PAREN");
	match("PERIOD");
}

void DatalogProgram::rule()
{
	headPredicate();
	match("COLON_DASH");
	predicate();
	predicateList();
	match("PERIOD");
}

void DatalogProgram::query()
{
	predicate();
	match("Q_MARK");
}

void DatalogProgram::headPredicate()
{
	match("ID");
	match("LEFT_PAREN");
	match("ID");
	idList();
	match("RIGHT_PAREN");
}

void DatalogProgram::predicate()
{
	match("ID");
	match("LEFT_PAREN");
	parameter();
	paramenterList();
	match("RIGHT_PAREN");
}

void DatalogProgram::predicateList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		predicate();
		predicateList();
	}
}

void DatalogProgram::paramenterList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		parameter();
		paramenterList();
	}
}

void DatalogProgram::stringList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		match("STRING");
		stringList();
	}
}

void DatalogProgram::idList()
{
	if (tokens.at(i).getType() == "COMMA")
	{
		match("COMMA");
		match("ID");
		idList();
	}
}

void DatalogProgram::parameter()
{
	if (tokens.at(i).getType() == "STRING")
	{
		match("STRING");
	}
	else if (tokens.at(i).getType() == "ID")
	{
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
	parameter();
	operatorasdf();
	parameter();
	match("RIGHT_PAREN");
}

void DatalogProgram::operatorasdf()
{
	if (tokens.at(i).getType() == "ADD")
	{
		match("ADD");
	}
	else
	{
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
		headPredicate();
		match("COLON_DASH");
		predicate();
		predicateList();
		match("PERIOD");
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
