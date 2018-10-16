#include "pch.h"
#include <iostream>
#include "Collumn.h"
#include "Table.h"
#include <vector>

int main()
{
	vector <Collumn*> vec1;
	Collumn col(2, "test", 12, "Horro");
	Collumn *co = &col;
	vec1.emplace_back(co);
	Table tab(vec1);
	tab.Table::insertValues(tab, "title", 12, "gerne");
	std::cout << "Hello World!\n";
	std::cout << "Hello World!\n";
	tab.Table::getNumber(tab, "searchTitle", 12, "Horro");
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
