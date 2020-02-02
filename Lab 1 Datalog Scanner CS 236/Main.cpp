#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"

using namespace std;

int main(int argc, char** argv)
{
	ofstream out(argv[2]);
	string fileName = argv[1];
	Tokenizer tokenizer(fileName);

	out << tokenizer.scan();
	return 0;
}