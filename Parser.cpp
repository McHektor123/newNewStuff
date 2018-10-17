#include "pch.h"
#include "Parser.h"
#include <string>
#include <iostream>
#include "Table.h"

using namespace std;

Parser::Parser()
{
}

void Parser::parseString(Table &tab, string Input) {
	string validCalls("delete, select, insert");
	string demiliterSpace(" ");
	string demiliterEnd(";");
	size_t präfixPos = Input.find_first_of(demiliterSpace);
	string präfix = Input.substr(0, präfixPos);
	if (validCalls.find(präfix) == string::npos) {
		cout << "Wrong argument, use something else" << endl;
	}
	if (präfix == "delete") {
		size_t firstEQ = Input.find_first_of("=");
		size_t firstEnd = Input.find_first_of(demiliterEnd);
		string argument = Input.substr(firstEQ+2, firstEnd);
		argument.pop_back();
		string operation = Input.substr(präfixPos, firstEQ);
		if (operation.find(" gerne =") != string::npos || operation.find(" gerne=") != string::npos) {
			tab.Table::deleteWitGerne(argument, false);
		}
	}
}

Parser::~Parser()
{
}
