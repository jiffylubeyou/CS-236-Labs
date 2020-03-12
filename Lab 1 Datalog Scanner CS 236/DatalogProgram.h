#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include <iostream>
#include <vector>
#include <sstream>
#include "Token.h"
#include "Tokenizer.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"

using namespace std;

class DatalogProgram
{
public:
	DatalogProgram(vector<Token> tokens) { this->tokens = tokens; }
	DatalogProgram();
	~DatalogProgram();

	void datalogProgram();
	void match(string typeID);
	void schemeList();
	void factList();
	void ruleList();
	void queryList();
	void scheme();
	void fact();
	void rule();
	void query();
	void headPredicate();
	void predicate();
	void predicateList();
	void paramenterList();
	void stringList();
	void idList();
	void parameter();
	void expression();
	void operatorasdf();
	vector<Predicate> getSchemes() { return schemes; }
	vector<Predicate> getFacts() { return facts; }
	vector<Rule> getRules() { return rules; }
	vector<Predicate> getQueries() { return queries; }

	string toString();

protected:
	int i = 0;
	vector<Token> tokens;

	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Rule> rules;
	vector<Predicate> queries;
	Predicate tempPredicate;
	string tempParameter;
	Rule tempRule;
};

#endif