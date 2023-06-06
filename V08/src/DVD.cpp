/*
 * DVD.cpp
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#include "DVD.h"

/**
 * @brief Konstruktor mit Parametern
 * @param initTitel Titel
 * @param initAltersfreigabe Altersfreigabe
 * @param initGenre Genre
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) :
		Medium(initTitel), altersFreigabe(initAltersfreigabe), genre(initGenre)
{
}

/*
 * @brief Standarddestruktor
 */
DVD::~DVD()
{
}

/**
 * @brief Ausgabefunktion mit Vererbung aus Basisklasse Medium
 */
void DVD::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "FSK: ab " << altersFreigabe << " Jahren" << std::endl;
	std::cout << "Genre: " << genre << std::endl;
}

/**
 * @brief Überladung der Ausleihfunktion der Basisklasse Medium
 * @param person die ausleihende Person
 * @param ausleihdatum Ausleihdatum
 * @return true, wenn das Medium ausgeliehen wird, false wenn nicht.
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
	Datum aktuellesDatum;
	if (this->altersFreigabe <= abs((person.getGeburtsdatum() - aktuellesDatum) / 12))
	{
		Medium::ausleihen(person, ausleihdatum);
		return true;
	}
	else
	{
		std::cout << "Die Person ist zu jung."<<std::endl;
		return false;
	}
}
