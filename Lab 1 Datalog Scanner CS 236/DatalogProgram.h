#include <iostream>
#include <vector>
#include "Token.h"
#include "Tokenizer.h"

using namespace std;

class DatalogProgram
{
public:
	DatalogProgram(vector<Token> tokens) { this->tokens = tokens; }
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

	

protected:
	int i = 0;
	vector<Token> tokens;
};

