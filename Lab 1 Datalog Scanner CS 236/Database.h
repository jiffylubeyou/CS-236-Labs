#ifndef DATABASE_H
#define DATABASE_H
#include "Relation.h"

#include <map>

using namespace std;

class Database : map<string, Relation>
{
public:
	Database();
	~Database();
private:
	map<string, Relation>;
};

#endif