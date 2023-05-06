///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

// Verschlüsselungsfunktion
// @param schluessel ist die Lookup Tabelle
// @param wort ist das zu verschlüsselnde Wort
string verschluesseln(char schluessel[2][26], string wort)
{
	// Iteration durch die Buchstaben des Wortes und verschlüsseln des Buchstaben mit dem Schlüssel
	for(int i = 0; i < wort.length(); i++) {
		// Berechnugn der Alphabetposition (siehe vorherige Versuche)
		int alphabetPos = wort[i] % 32;
		wort[i] = schluessel[1][alphabetPos - 1];
	}

	return wort;
}

// Entschlüsselungsfunktion
// @param schluessel ist die Lookup Tabelle
// @param wort ist das verschlüsselte Wort
string entschluesseln(char schluessel[2][26], string wort)
{
	// Iteration durch die Buchstaben des Wortes und entschlüsseln des Buchstaben mit dem Schlüssel
	for(int i = 0; i < wort.length(); i++) {
		// Iteration durch das Alphabet
		for(int j = 0; j < 26; j++) {
			// Wenn der Buchstabe gefunden wurde, wird an die selbe Stelle beim entschlüsselten Wort der entschlüsselte Buchstabe gesetzt
			if(wort[i] == schluessel[1][j]) {
				wort[i] = schluessel[0][j];
				break;
			}
		}
	}
	return wort;
}

int main()
{
	// Lookup Tabelle für beide Funktionen
	char lookup[2][26] =
	{
		{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
		{'C','E','F','U','H','B','K','V','D','Z','O','I','Q','A','M','S','X','W','R','P','N','J','T','G','Y','L'}
	};

	// Eingabe des zu verschlüsselnden Wortes
	string wort;
	cout << "Bitte gebe ein zu verschlüsselndes Wort ein: " << endl;
	cin >> wort;

	// Wortverschlüsselung
	string verschluesseltesWort = verschluesseln(lookup, wort);
	cout << "Verschlüsselte Wort: " << verschluesseltesWort << endl;

	// Wortentschlüsselung
	string entschluesseltesWort = entschluesseln(lookup, verschluesseltesWort);
	cout << "Entschlüsseltes Wort: " << entschluesseltesWort << endl;

	return 0;
}
