#include "pch.h"
#include "Utils.h"
#include "Parser.h"
#include <string>
#include <iostream>
#include "Table.h"

using namespace std;

Parser::Parser()
{
}

Parser::~Parser()
{
}

void Parser::parseString(Table &tab, string Input) {
	string validCalls("deleteAll,delete, select, insert, DELETEALL, DELETE, SELECT, INSERT");
	string demiliterSpace(" ");
	size_t temp = 0;
	vector<string> arguments;
	for (size_t c = 0; c < Input.size(); c++) {
		if (Input[ c ] == ' ' || Input[c] == ';') {
			arguments.push_back(Input.substr(temp, c-temp));
				temp = c+1;
		}
	}
	if (validCalls.find(arguments[0]) == string::npos) {
		cout << "Invalid operation call, use something else" << endl;
	}
	if ((arguments[0] == "delete" || arguments[0] ==  "deleteAll" || arguments[0] ==  "DELETE" || arguments[0] == "DELETEALL") && arguments.size() >= 3) {
		bool all = arguments[0] == "deleteAll" || arguments[0] == "DELTEALL";
		if (arguments[1] == "gerne" || arguments[1] ==  "GERNE") {
			tab.deleteWitString(arguments[2], all, Utils::gerne);
		}
		if (arguments[1] == "title" || arguments[1] ==  "TITLE") {
			tab.deleteWitString(arguments[2], all, Utils::title);
		}
		try {
			if (arguments[1] == "number"|| arguments[1] ==  "NUMBER") {
				tab.deleteWithInt(stoi(arguments[2]), all, Utils::number);
			}
			if (arguments[1] == "rating" || arguments[1] ==  "RATING") {
				tab.deleteWithInt(stoi(arguments[2]), all, Utils::rating);
			}
			if (arguments[1] == "length" || arguments[1] ==  "LENGTH" ) {
				tab.deleteWithInt(stoi(arguments[2]), all, Utils::length);
			}
		}
		catch (exception& )
		{
			cout << " Wrong syntax for Lenght/Number/Rating used " << endl;
		}
	}
	try 
	{
		if ((arguments[0] == "select" || arguments[0] ==  "SELECT") && arguments.size() >= 2) {
			tab.selectValues(arguments[1]);
		}
	}
	catch (const std::exception&) {
		cout << " Missing argument for select" << endl;
	}
	try
	{
		if ((arguments[0] == "insert" || arguments[0] == "INSERT") && arguments.size() >= 5) {
			tab.insertValues(arguments[1], stoi(arguments[2]), arguments[3], stoi(arguments[4]));
		}
	}
	catch (const std::exception&)
	{
		cout << " Wrong syntax for Lenght/Rating used " << endl;
	}
}


