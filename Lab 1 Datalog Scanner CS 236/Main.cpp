#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

//#include "Tokenizer.h"
#include "DatalogProgram.h"

using namespace std;

int main(int argc, char** argv)
{
	//ofstream out(argv[2]);
	string fileName = argv[1];
	Tokenizer tokenizer(fileName);
	bool passed = true;

	tokenizer.scan();
	DatalogProgram datalogprogram(tokenizer.getTokens());
	try
	{
		datalogprogram.datalogProgram();
	}
	catch (Token t)
	{
		cout << "Failure!" << endl << "  " << t.toString() << endl;
		passed = false;
	}
	if (passed)
	{
		cout << datalogprogram.toString();
	}
	return 0;
}