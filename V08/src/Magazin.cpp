/*
 * Magazin.cpp
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#include "Magazin.h"

/**
 * @brief Konstruktor mit Parametern
 * @param initTitel Titel
 * @param initDatumAusgabe Herausgabedatum der Ausgabe
 * @param initSparte Sparte
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
		: Medium(initTitel), ausgabeDatum(initDatumAusgabe), sparte(initSparte)
{
}

/**
 * @brief Standarddestruktor
 */
Magazin::~Magazin()
{
}

/**
 * @brief Ausgabefunktion mit Vererbung aus Basisklasse Medium
 */
void Magazin::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "Ausgabe: " << ausgabeDatum << std::endl;
	std::cout << "Sparte: " << sparte << std::endl;
}

/**
 * @brief Überladung der Ausleihfunktion der Basisklasse Medium
 * @param person Daten der ausleihenden Person
 * @param ausleihdatum Ausleihdatum
 * @return true, wenn das Medium ausgeliehen wird. Falls, wenn nicht.
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	// neuste Ausgabe 0 Monate?
	if (abs(this->ausgabeDatum - ausleihdatum) != 0)
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}

	else
	{
		std::cout << "Es handelt sich um die neueste Ausgabe des Magazins." << std::endl;
		return false;
	}
}
