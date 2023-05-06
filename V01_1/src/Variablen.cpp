//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

// Funktionen der C++ Standardbilbiothek können ohne Angabe des Namespaces (std)
// genutzt werden.
using namespace std;

// Einstiegspunkt des Programms
int main() {
    int iErste = 0;
    int iZweite = 0;
    
    // Aufgabe 1.6.1: Datentypen & Typumwandlung
    // UP1
    cout << "Eingabe der ersten Zahl iErste: " << endl;
    cin >> iErste;
    cout << "Eingabe der zweiten Zahl iZweite: " << endl;
    cin >> iZweite;

    // Integeraktionen
    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite;
    cout << "iSumme: " << iSumme << endl;
	cout << "iQuotient: " << iQuotient << endl;

	// UP2
    // Doubleaktionen
    // Weiterhin keine Änderung, da die Integer nicht in double umgewandelt werden
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    cout << "dSumme: " << dSumme << endl;
    cout << "dQuotient: " << dQuotient << endl;

    // UP3
    // Änderung, da die Integer in double umgewandelt werden, so sind Nachkommastellen möglich
    double dSummeCast = (double) iErste + (double) iZweite;
	double dQuotientCast = (double) iErste / (double) iZweite;
	cout << "dSummeCast: " << dSummeCast << endl;
	cout << "dQuotientCast: " << dQuotientCast << endl;


	// UP4
	// Definition des Vor- und Nachnamen
	string sVorname, sNachname;

	// Einlesevorgang
	cout << "Bitte gebe deinen Vornamen ein: " << endl;
	cin >> sVorname;
	cout << "Bitte gebe deinen Nachnamen ein: " << endl;
	cin >> sNachname;

	// Nutzung des +-Operators für Strings
	string sVornameName = sVorname + " " + sNachname;
	string sNameVorname = sNachname + ", " + sVorname;

	// Ausgabe
	cout << "sVornameName: " << sVornameName << endl;
	cout << "sNameVorname: " << sNameVorname << endl;

	// UP5a
	// Eigenständiger Block
	// Innerhalb dieses Blocks definierte Variablen werden am Ende des Blocks gelöscht
	// dementsprechend können sie nur innerhalb des Blocks aufgerufen werden
	{
		int iFeld[2] = {1, 2};
		for(int i = 0; i < 2; i++) {
			cout << "iFeld[" << i << "]: " << iFeld[i] << endl;
		}
	}

	// UP5b
	{
		// 2x3 Matrix
		// [ 1 2 3 ]
		// [ 4 5 6 ]
		int spielfeld[2][3] = {{1, 2, 3}, {4, 5, 6}};

		// Ausgabe jeder Zeile mit Leerzeichen zwischen Elementen
		for(int i = 0; i < 2; i++) {
			cout << "spielfeld[" << i << "]:";
			for(int j = 0; j < 3; j++) {
				cout << " " << spielfeld[i][j];
			}
			cout << endl;
		}
	}

	// UP5c
	{
		// Überschreibung von iZweite für innerhalb des Blocks
		const int iZweite = 1;
		cout << "Konstante iZweite: " << iZweite << endl;
	}
	// Da der Block zu Ende ist wird der Wert von iZweite wieder von außerhalb des Blocks genommen
	cout << "Oben deklarierte iZweite: " << iZweite << endl;

	// UP6&7
	if(sVorname.length() < 2) {
		cout << "Die Länge des Vornamen muss 2 oder größer sein." << endl;
	} else {
		// UP6
		// Durch die Deklarierung als Variable wird der Buchstabe automatisch in den entsprechenden
		// ASCII-Code umgewandelt
		char iName1 = sVorname[0];
		char iName2 = sVorname[1];

		cout << "Erster Buchstabe des Vornamen: " << iName1 << endl;
		cout << "Zweiter Buchstabe des Vornamen: " << iName2 << endl;

		// UP7
		// Nutzung von 32, da in der ASCII-Tabelle ein Abstand von 32 zwischen
		// Klein- und Großbuchstaben ist. Durch die Nutzung des Operators Modulo
		// weiß man also immer, wie viele Buchstaben man schon im Alphabet weit ist.
		// 65: A
		// 66: B
		// ..
		// 97: a
		// 98: b
		// ..
		int iPos1 = iName1 % 32;
		int iPos2 = iName2 % 32;

		cout << "Alphabetposition des zweiten Buchstaben des Vornamen: " << iPos1 << endl;
		cout << "Alphabetposition des ersten Buchstaben des Vornamen: " << iPos2 << endl;
	}

    return 0;
}
