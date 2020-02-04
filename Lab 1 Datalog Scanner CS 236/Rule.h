#pragma once
#include <vector>
#include "Predicate.h"

using namespace std;

class Rule
{
public:
	Rule();
	~Rule();
protected:
	Predicate headPredicate;
	vector<Predicate> predicates;
};

