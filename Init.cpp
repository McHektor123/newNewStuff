#include <string>
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

	string test;
	//while (true) {
		//getline(std::cin, test);
		//Parser::parseString(tab2, test);
	//}

	//Parser::parseString(tab2, "select Fc ;");
	//Parser::parseString(tab2, "select aws ;");
	Writer::print(tab2.getRows());
	//number wird automatisch generiert und ist nur im select einsehrbar
	//Parser::parseString(tab2, "deleteAll genre Sci;");
	//Parser::parseString(tab2, "deleteAll length 12;");
	//Parser::parseString(tab2, "deleteAll rating 10;");

	return 0;
}
//backlock: suggestions durch longest sup-sequence und group durch hashing
// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.


