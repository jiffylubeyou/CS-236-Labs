#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

#include "Token.h"

using namespace std;

class Tokenizer
{
public:
	Tokenizer(string fileName) { this->fileName = fileName; };
	~Tokenizer();

	string scan();
	vector<Token> getTokens()
	{
		return tokens;
	}
protected:
	string fileName;
	vector<Token> tokens;
};
#endif

