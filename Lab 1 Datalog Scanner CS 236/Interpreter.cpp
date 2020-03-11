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
}
