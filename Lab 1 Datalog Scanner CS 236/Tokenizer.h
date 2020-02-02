#include <iomanip>
#include <sstream>
#include <fstream>
#include "Token.h"
using namespace std;

class Tokenizer
{
public:
	Tokenizer(string fileName) { this->fileName = fileName; };
	~Tokenizer();

	string scan();
protected:
	string fileName;
};

