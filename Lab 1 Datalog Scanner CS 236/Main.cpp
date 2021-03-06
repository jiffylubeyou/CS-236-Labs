#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

//#include "Tokenizer.h"
#include "Interpreter.h"

using namespace std;

int main(int argc, char** argv)
{
	//ofstream out(argv[2]);
	string fileName = argv[1];
	Tokenizer tokenizer(fileName);

	tokenizer.scan();
	DatalogProgram datalogprogram(tokenizer.getTokens());
	try
	{
		datalogprogram.datalogProgram();
	}
	catch (Token t)
	{
		cout << "Failure!" << endl << "  " << t.toString() << endl;
	}
	Interpreter interpreter(datalogprogram);
	cout << interpreter.EvaluateAll();
	return 0;
}