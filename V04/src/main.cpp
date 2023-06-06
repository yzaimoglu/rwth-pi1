//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define PI 3.14159265359
#define ERDRADIUS 6371
#define ROTATERAD PI/300000000
#define EPSILON 0.01

using namespace std;

int main()
{
	// Testen
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    vector1.ausgabe();
    vector2.ausgabe();

    // Wie weit entfernt ist der Horizont?
    int anzahlSchritte = 0;
    double koerperGroesse = 1.70;
    double plattformHoehe = 555.7;

    // Vektor, der den Menschen beschreibt, der auf der hohen Plattform steht
    // const, da dieser sich nicht ändert
	Vektor const mensch(0, (plattformHoehe + koerperGroesse) / 1000 + ERDRADIUS, 0);

	// Vektor, der die Erde beschreibt
	Vektor erde(0, ERDRADIUS, 0);

	// Vektor, der vom Auge des Menschen ausgeht
	// Sicht des Menschen
	Vektor augenVektor = erde.sub(mensch);

	// Wiederholung bis der Skalarprodukt fast 0 ist, also die Vektoren orthogonal sind
	while (augenVektor.skalarProd(erde) >= EPSILON || augenVektor.skalarProd(erde) <= -1 * EPSILON)
	{
		// Rotation des Erdvektors mit einem konstanten Faktor,
		erde.rotiereUmZ(ROTATERAD);
		augenVektor = erde.sub(mensch);

		anzahlSchritte++;
	}

	cout << fixed;
	cout << setprecision(4);
	cout << "Sie können " << augenVektor.laenge() << " Km weit sehen" << endl;
	cout << "Sie sind " << plattformHoehe << " Meter hoch." << endl;
	cout << "Der Winkel beträgt " << mensch.winkel(erde) << " Grad." << endl;
	cout << "Anzahl Schritte: " << anzahlSchritte << endl;

	return 0;
}
