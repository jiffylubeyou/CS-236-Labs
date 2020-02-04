#pragma once
#include "DatalogProgram.h"

class Predicate
{
public:
	Predicate();
	~Predicate();
protected:
	vector<Parameter> parameters;
};

