//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Student.h"

/**
 * @brief Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 *
 * @param matNr Matrikelnummer
 * @param name Name
 * @param geburtstag Geburtstag
 * @param adresse Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Gibt die Matrikelnummer des Studenten zurueck
 *
 * @return Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief Gibt den Namen des Studenten zurueck
 *
 * @return Name
 */
std::string Student::getName() const
{
    return name;
}

/**
 * @brief Gibt den Geburtstag des Studenten zurueck
 *
 * @return Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief Gibt die Adresse des Studenten zurueck
 *
 * @return Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

// /**
//  * @brief Gibt alle Daten des Studenten in einer Zeile aus
//  */
// void Student::ausgabe() const
// {
//     std::cout << name << ", MatNr. " << matNr << ", geb. am "
//               << geburtstag << ", wohnhaft in " << adresse
//               << std::endl;
// }

/**
 * @brief Gibt alle Daten des Studenten in einer Zeile aus
 * @param ausgabe Ausgabestream
 * @return Ausgabestream
 */
void Student::ausgabe(std::ostream& ausgabe) const
{
    ausgabe << name << ", MatNr. " << matNr << ", geb. am "
            << geburtstag << ", wohnhaft in " << adresse
            << std::endl;
}


/**
 * @brief Überladen des ==-Operators zum Vergleich von Matrikelnummern
 * @param student der zu vergleichende Student
 * @return true wenn die Matrikelnummern übereinstimmen, false wenn nicht
 */
bool Student::operator ==(const Student& student) const
{
	if (this->matNr == student.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Überladen des <-Operators zum Vergleich von Matrikelnummern
 * @param student der zu vergleichende Student
 * @return true wenn die Matrikelnummer kleiner ist, false wenn nicht
 */
bool Student::operator <(const Student& student) const
{
	if (this->matNr < student.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Überladen des >-Operators zum Vergleich von Matrikelnummern
 * @param student der zu vergleichende Student
 * @return true wenn die Matrikelnummer gröeßer ist, false wenn nicht
 */
bool Student::operator >(const Student& student) const
{
	if(this->matNr > student.matNr)
		return true;
	else
		return false;
}

/**
 * @brief Überladen des <<-Operators zum Ausgeben eines Studenten
 * @param ausgabe Ausgabestream
 * @param student der auszugebende Student
 * @return Ausgabestream
 */
std::ostream& operator << (std::ostream& ausgabe, const Student& student) {
    student.ausgabe(ausgabe);
    return ausgabe;
}

