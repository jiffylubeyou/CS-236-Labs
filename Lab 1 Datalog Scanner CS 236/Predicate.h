#pragma once
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate
{
public:
	Predicate();
	~Predicate();
protected:
	string name;
	vector<Parameter> parameters;
};

