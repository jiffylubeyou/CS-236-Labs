#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "DatalogProgram.h"
#include "Database.h"

using namespace std;

class Interpreter
{
public:

	Interpreter(DatalogProgram datalogProgram) { this->datalogProgram = datalogProgram; populateInterpreter(); }
	~Interpreter();

	void populateInterpreter();

private:
	DatalogProgram datalogProgram;
	vector<Predicate> schemes;
	vector<Predicate> facts;
	vector<Rule> rules;
	vector<Predicate> queries;
	Database database;
};

#endif