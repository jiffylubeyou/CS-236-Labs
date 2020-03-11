#ifndef RELATION_H
#define RELATION_H

#include <set>

#include"Tuple.h"
#include"Scheme.h"

using namespace std;

class Relation
{
public:
	Relation();
	~Relation();

private:
	Scheme scheme;
	set<Tuple> tuples;
	string name;
};
#endif