#include "Tokenizer.h"


Tokenizer::~Tokenizer()
{
}

string Tokenizer::scan()
{
	int lineNum = 1;
	int total = 0;
	ifstream in(fileName);
	ostringstream out;	
	while (in)
	{
		char asciiChar = in.peek();
		if (asciiChar == ',')
		{
			Token token;
			token.setType("COMMA");
			token.setValue(",");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			in.ignore();
		}

		else if (asciiChar == '.')
		{
			Token token;
			token.setType("PERIOD");
			token.setValue(".");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			in.ignore();
		}

		else if (asciiChar == '?')
		{
			Token token;
			token.setType("Q_MARK");
			token.setValue("?");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			in.ignore();
		}

		else if (asciiChar == '(')
		{
			Token token;
			token.setType("LEFT_PAREN");
			token.setValue("(");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			in.ignore();
		}

		else if (asciiChar == ')')
		{
			Token token;
			token.setType("RIGHT_PAREN");
			token.setValue(")");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			in.ignore();
		}

		else if (asciiChar == ':')
		{
			in.ignore();
			if (in.peek() == '-')
			{
				Token token;
				token.setType("COLON_DASH");
				token.setValue(":-");
				out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
				total++;
				in.ignore();
			}
			else
			{
			Token token;
			token.setType("COLON");
			token.setValue(":");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			}
		}

		else if (asciiChar == '*')
		{
		Token token;
		token.setType("MULTIPLY");
		token.setValue("*");
		out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
		total++;
		in.ignore();
		}

		else if (asciiChar == '+')
		{
		Token token;
		token.setType("ADD");
		token.setValue("+");
		out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
		total++;
		in.ignore();
		}

		//for IDs
		else if (isalpha(asciiChar))
		{
		Token token;
		string tempString;
		char tempChar;
		in.get(tempChar);
		tempString.push_back(tempChar);
		while ((isalpha(in.peek())) || (isdigit(in.peek())))
		{
			in.get(tempChar);
			tempString.push_back(tempChar);
		}
		if (tempString == "Schemes")
		{
			token.setType("SCHEMES");
			token.setValue("Schemes");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
		else if (tempString == "Facts")
		{
			token.setType("FACTS");
			token.setValue("Facts");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
		else if (tempString == "Rules")
		{
			token.setType("RULES");
			token.setValue("Rules");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
		else if (tempString == "Queries")
		{
			token.setType("QUERIES");
			token.setValue("Queries");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
		else
		{
			token.setType("ID");
			token.setValue(tempString);
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
		}

		else if (asciiChar == '\'')
		{
			Token token;
			string tempString;
			char tempChar;
			int endLineNum = lineNum;
			bool isdefined = true;
			in.get(tempChar);
			tempString.push_back(tempChar);
			while (in.peek() != '\'')
			{
				if (in.peek() == EOF)
				{
					token.setType("UNDEFINED");
					token.setValue(tempString);
					out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << endLineNum << ")" << endl;
					total++;
					isdefined = false;
					break;
				}
				in.get(tempChar);
				tempString.push_back(tempChar);
				if (tempChar == '\n')
				{
					lineNum++;
				}
				/*if ((tempChar == '\'')) //&& (in.peek() == '\''))
				{
					in.ignore();
					continue;
				}*/
			}
			if (isdefined)
			{
				tempString.push_back('\'');
				token.setType("STRING");
				token.setValue(tempString);
				out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << endLineNum << ")" << endl;
				total++;
				in.ignore();
			}
			else
			{
				Token token;
				token.setType("EOF");
				token.setValue("");
				out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
				total++;
			}
		}

		else if (asciiChar == '#')
		{
			in.ignore();
			Token token;
			string tempString;
			char tempChar;
			int endLineNum = lineNum;
			bool isdefined = true;
			if ( in.peek() == '|')
			{
				in.ignore();
				tempString.push_back('#');
				tempString.push_back('|');
				while (1 == 1)
				{
					if (in.peek() == EOF)
					{
						token.setType("UNDEFINED");
						token.setValue(tempString);
						out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << endLineNum << ")" << endl;
						total++;
						isdefined = false;
						break;
					}
					in.get(tempChar);
					tempString.push_back(tempChar);
					if (tempChar == '\n')
					{
						lineNum++;
					}
					if (tempChar == '|')
					{
						if (in.peek() == '#')
						{
							tempString.push_back('#');
							in.ignore();
							break;
						}
					}
				}
			}
			else
			{
				tempString.push_back('#');
				while ((in.peek() != '\n') && (in.peek() != EOF))
				{
					in.get(tempChar);
					tempString.push_back(tempChar);
				}
				if (in.peek() == EOF)
				{
					Token token;
					token.setType("EOF");
					token.setValue("");
					out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
					total++;
				}
			}
			if (isdefined)
			{
				token.setType("COMMENT");
				token.setValue(tempString);
				out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << endLineNum << ")" << endl;
				total++;
			}
		}

		else if (asciiChar == '\n')
		{
			lineNum++;
			in.ignore();
		}

		else if (isspace(asciiChar))
		{
			in.ignore();
		}

		else if (asciiChar == EOF)
		{
			Token token;
			token.setType("EOF");
			token.setValue("");
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
			break;
		}

		else 
		{
			Token token;
			string tempString;
			char tempChar;
			in.get(tempChar);
			tempString.push_back(asciiChar);
			token.setType("UNDEFINED");
			token.setValue(tempString);
			out << "(" << token.getType() << ",\"" << token.getValue() << "\"," << lineNum << ")" << endl;
			total++;
		}
	}
	out << "Total Tokens = " << total << endl;
	return out.str();
}
