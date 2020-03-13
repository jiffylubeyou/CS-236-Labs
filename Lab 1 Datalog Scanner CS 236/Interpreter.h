#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <unordered_map>

#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"

using namespace std;

class Interpreter
{
public:

	Interpreter(DatalogProgram datalogProgram) { this->datalogProgram = datalogProgram; populateInterpreter();
	populateDatabase(); }
	~Interpreter();

	void populateInterpreter();
	void populateDatabase();
	Relation EvaluateQuery(Predicate query);
	string EvaluateAll();

protected:
	DatalogProgram datalogProgram;
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Rule> rules;
	vector<Predicate> queries;
	Database database;
};

#endif