#include "pch.h"
#include <iostream>
#include "Row.h"
#include "Table.h"
#include <vector>

int main()
{
	//vector <Row*> vec1;
	//Row col(0, "asd", 15, "gerne");
	//Row *co = &col;
	//Row col2(1, "asd", 2, "asd");
	//Row *co2 = &col2;
	//vec1.push_back((co));
	//vec1.push_back((co2));
	//Table tab(vec1);
	//tab.Table::selectValues(1);
	//tab.Table::deleteValues(0, "asd", 15, "gerne");


	//tab.Table::selectValues("gerne");
	//tab.Table::selectValues(1);
	//tab.Table::selectValues(15);
	//sadsa
	vector <Row*> vec2;
	Table tab2(vec2);
	tab2.Table::insertValues("title", 12, "Horro");
	Row *cik = tab2.Table::getRows()[0];
	tab2.Table::deleteValues(1, "title", 12, "Horro");
	tab2.Table::selectValues("title");
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
