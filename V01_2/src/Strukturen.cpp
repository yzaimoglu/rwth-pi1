/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	// Struktur Person
	struct Person {
		string sNachname, sVorname;
		int iGeburtsjahr, iAlter;
	};

	// Definition eines Benutzers
	Person nBenutzer;

	// Eingabe der Daten des Benutzers
	cout << "Gebe bitte deinen Vornamen ein: " << endl;
	cin >> nBenutzer.sVorname;
	cout << "Gebe bitte deinen Nachnamen ein: " << endl;
	cin >> nBenutzer.sNachname;
	cout << "Gebe bitte dein Geburtsjahr ein: " << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Gebe bitte dein Alter ein: " << endl;
	cin >> nBenutzer.iAlter;

	// Ausgabe des Nutzers
	cout << endl << nBenutzer.sNachname << ", " << nBenutzer.sVorname << ": " << endl;
	cout << setfill('-') << setw(15) << "" << endl;
	cout << "Geburtstsjahr: " << nBenutzer.iGeburtsjahr << endl;
	cout << "Alter: " << nBenutzer.iAlter << endl;

	// Definition, Deklaration & Ausgabe von nKopieEinzeln
	Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	cout << endl << nKopieEinzeln.sNachname << ", " << nKopieEinzeln.sVorname << ": " << endl;
	cout << setfill('-') << setw(15) << "" << endl;
	cout << "Geburtstsjahr: " << nKopieEinzeln.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieEinzeln.iAlter << endl;

	// Definition, Deklaration & Ausgabe von nKopieGesamt
	Person nKopieGesamt = nBenutzer;
	cout << endl << nKopieGesamt.sNachname << ", " << nKopieGesamt.sVorname << ": " << endl;
	cout << setfill('-') << setw(15) << "" << endl;
	cout << "Geburtstsjahr: " << nKopieGesamt.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieGesamt.iAlter << endl;
    return 0;
}


