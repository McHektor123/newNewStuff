﻿#include <string>
#include <vector>
#include "pch.h"
#include "Row.h"
#include "Table.h"
#include "Parser.h"
#include "Writer.h"
#include <iostream>

using namespace std;
int main()
{
	vector <Row*> vec2;
	Table tab2(vec2);
	Parser::parseString(tab2, "insert Herr_der_Ringe_I 131 Fantasy 10;");
	Parser::parseString(tab2, "insert Herr_der_Ringe_I 131 Fantasy 10;");
	//Parser::parseString(tab2, "deleteAll gerne Fantasy;");
	Parser::parseString(tab2, "select Herr;");
	Parser::parseString(tab2, "select Her;");
	Parser::parseString(tab2, "select Fc ;");
	Parser::parseString(tab2, "select aws ;");
	Writer::print(tab2.getRows());
	Parser::parseString(tab2, "deleteAll genre Sci;");
	Parser::parseString(tab2, "deleteAll length 12;");
	Parser::parseString(tab2, "deleteAll rating 10;");

	return 0;
}

