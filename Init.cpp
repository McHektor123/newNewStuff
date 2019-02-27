#include "pch.h"
#include <iostream>
#include "Collumn.h"
#include "Table.h"
#include <vector>
#include "Parser.h"

int main()
{

	vector <Collumn*> vec2;
	Table tab2(vec2);

	Parser::parseString(tab2, "insert Star 13 Fantasy 10;");
	Parser::parseString(tab2, "insert Wars 13 Fantasy 10;");
	Parser::parseString(tab2, "insert The 13 Sci 10;");
	Parser::parseString(tab2, "insert End 13 Fic 10;");
	Parser::parseString(tab2, "insert End 13 Fac 10;");
	Parser::parseString(tab2, "insert Herr 13 Tion 10;");
	Parser::parseString(tab2, "insert Herr 13 Tian 10;");
	Parser::parseString(tab2, "insert Herr 13 Auto 10;");
	Parser::parseString(tab2, "insert Herr 13 Fantasy 10;");
	Parser::parseString(tab2, "insert Herr 12 Mystery 10;");
	Parser::parseString(tab2, "insert Herr 14 Fantasy 10;");
	Parser::parseString(tab2, "select fan ;");
	Parser::parseString(tab2, "select me ;");
	Parser::parseString(tab2, "select Fc ;");
	Parser::parseString(tab2, "select Tin ;");
	Parser::parseString(tab2, "select Aauto ;");
	Parser::parseString(tab2, "select Ato ;");
	//number wird automatisch generiert und ist nur im select einsehrbar
	Parser::parseString(tab2, "deleteAll number 4;");
	Parser::parseString(tab2, "deleteAll title End;");
	Parser::parseString(tab2, "deleteAll genre Sci;");
	Parser::parseString(tab2, "deleteAll length 12;");
	Parser::parseString(tab2, "deleteAll rating 10;");

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


