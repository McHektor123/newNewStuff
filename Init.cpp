#include "pch.h"
#include <iostream>
#include "Row.h"
#include "Table.h"
#include <vector>
#include "Parser.h"

int main()
{

	vector <Row*> vec2;
	Table tab2(vec2);
	tab2.Table::insertValues("title", 1, "hor");
	tab2.Table::insertValues("title2", 1, "ha");
	tab2.Table::insertValues("title3", 1, "Horror");
	tab2.Table::insertValues("title4", 12, "ha");
	tab2.Table::selectValues("*");
	tab2.Table::insertValues("title3", 1, "Horror");
	tab2.Table::insertValues("title4", 12, "ha");
	Parser::parseString(tab2,"delete gerne= Horror;");
	tab2.Table::selectValues("*");

	return 0;
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.


