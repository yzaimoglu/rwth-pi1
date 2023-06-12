/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIII <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Student.h"

void student_push_front(std::vector<Student> studentVector, Student student);
void student_pop_front(std::vector<Student> studentVector);
Student student_get(std::vector<Student> studentVector, int matrikelnummer);
void student_delete(std::vector<Student> studentVector, int matrikelnummer);
void student_print(std::vector<Student> studentVector);
void student_print_reverse(std::vector<Student> studentVector);
std::vector<Student> student_read_file(std::string dateiName);
void student_write_file(std::vector<Student> studentVector, std::string dateiName);

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    // std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    // std::cin >> abfrage;
    // std::cin.ignore(10, '\n');

    // if (abfrage != 'j')
    // {
    //     student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    //     studentenListe.push_back(student);
    //     student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
    //     studentenListe.push_back(student);
    //     student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    //     studentenListe.push_back(student);
    //     student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
    //     studentenListe.push_back(student);
    //     student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
    //     studentenListe.push_back(student);
    // }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank von vorne nach hinten ausgeben" << std::endl
                  << "(4): Datenbank von hinten nach vorne ausgeben" << std::endl
                  << "(5): Datenelement löschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl 
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        student_pop_front(studentenListe);
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    student_print(studentenListe);
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

			// Datenbank rueckwaerts ausgeben
            case '4':
				if(!studentenListe.empty())
				{
					std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
				    student_print_reverse(studentenListe);
                }
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
				break;
			// Löschen eines Studenten
            case '5':
            	if(!studentenListe.empty())
				{
            		unsigned int matrikelnummer = 0;
					std::cout << "Bitte gebe die Matrikelnummer des zu löschenden Studenten ein:" << std::endl;
					std::cin >> matrikelnummer;
					std::cin.ignore(10, '\n');

					student = student_get(studentenListe, matrikelnummer);
					if(student.getMatNr() != 0) {
						std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
						student.ausgabe();
						student_delete(studentenListe, matrikelnummer);
					} else {
						std::cout << "Der Student mit der Matrikelnummer " << matrikelnummer << " ist nicht in der Liste." << std::endl;
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!\n\n";
				}
            	break;
            // Datenelement vorne hinzufügen
            case '6':
				{
					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					student_push_front(studentenListe, student);
				}
            	break;
            // Daten aus einer Datei einlesen
            case '7':
            	{
            		std::string dateiName;
					std::cout
						<< "Einlesevorgang ist gestartet." << std::endl
						<< "Bitte geben Sie den Namen der Datei ein, die Sie einlesen wollen." << std::endl;

					std::cin >> dateiName;
					std::cin.ignore(10, '\n');
                    std::cout << "Die Datei heißt: " << dateiName << std::endl;

                    studentenListe.clear();
					studentenListe = student_read_file(dateiName);
					break;
            	}
            // Daten in eine Datei sichern
            case '8':
                {
                    std::string dateiName;
                    std::cout
                        << "Aulesevorgang ist gestartet." << std::endl
                        << "Bitte geben Sie den Namen der Datei ein, die Sie sichern wollen." << std::endl;

                    std::cin >> dateiName;
                    std::cin.ignore(10, '\n');
                    std::cout << "Die Datei heißt: " << dateiName << std::endl;

                    student_write_file(studentenListe, dateiName);
                    break;
                }
            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}

/**
 * @brief Fügt einen Studenten in den Vektor an erster Stelle ein
 * @param studentVector der Studentenvektor
 * @param student einzufügender Student
 * @return void
 */
void student_push_front(std::vector<Student> studentVector, Student student) {
    studentVector.insert(studentVector.begin(), student);
}

/**
 * @brief Löscht den ersten Studenten aus dem Vektor
 * @param studentVector der Studentenvektor
 * @return void
 */
void student_pop_front(std::vector<Student> studentVector) {
    studentVector.erase(studentVector.begin());
}

/**
 * @brief Erhält einen Studenten aus dem Vektor anhand der Matrikelnummer
 * @param studentVector der Studentenvektor
 * @param matrikelnummer Matrikelnummer des Studenten
 * @return Student
 */
Student student_get(std::vector<Student> studentVector, int matrikelnummer) {
    for(auto it = studentVector.begin(); it != studentVector.end(); ++it) {
        if(it->getMatNr() == matrikelnummer) {
            return *it;
        }
    };
    return Student(0, "", "", "");
}

/**
 * @brief Löscht einen Studenten aus dem Vektor anhand der Matrikelnummer
 * @param studentVector der Studentenvektor
 * @param matrikelnummer Matrikelnummer des zu löschenden Studenten
 * @return void
 */
void student_delete(std::vector<Student> studentVector, int matrikelnummer) {
    for(auto it = studentVector.begin(); it != studentVector.end(); ++it) {
        if(it->getMatNr() == matrikelnummer) {
            studentVector.erase(it);
        }
    };
}

/**
 * @brief Gibt den Studentenvektor in richtiger Reihenfolge aus
 * @param studentVector der auszugebende Vektor
 * @return void
 */
void student_print(std::vector<Student> studentVector) {
    for(auto it = studentVector.begin(); it != studentVector.end(); ++it) {
        it->ausgabe();
    };
}

/**
 * @brief Gibt den Studentenvektor in verkehrter Reihenfolge aus
 * @param studentVector der auszugebende Vektor
 * @return void
 */
void student_print_reverse(std::vector<Student> studentVector) {
    for(auto it = studentVector.rbegin(); it != studentVector.rend(); ++it) {
        it->ausgabe();
    };
}

/**
 * @brief Liest den Studentenvektor aus einer Datei
 * @param dateiName der Name der zu einlesenden Datei
 * @return studentVector
 */
std::vector<Student> student_read_file(std::string dateiName) {
    std::vector<Student> studentenListe;

    std::ifstream eingabe(dateiName);
    if(eingabe.is_open()) {
        unsigned int matNr;
        eingabe >> matNr;
        while(!eingabe.eof()) {
            std::string name;
            std::string geburtstag;
            std::string adresse;

            eingabe.ignore(1, '\n');
            getline(eingabe, name);
            getline(eingabe, geburtstag);
            getline(eingabe, adresse);

            Student student(matNr, name, geburtstag, adresse);
            std::cout << "Student " << name << " mit der Matrikelnummer " << matNr << " wurde eingefügt."<< std::endl;
            studentenListe.push_back(student);
            eingabe >> matNr;
        }
        std::cout << "Einlesevorgang ist beendet." << std::endl;
    } else {
        std::cout << "Datei konnte nicht geöffnet werden." << std::endl;
    }
    return studentenListe;
}

/**
 * @brief Speichert den Studentenvektor in eine Datei mit dem Namen ein
 * @param studentVector der Studentenvektor
 * @param dateiName der Name der zu speichernden Datei
 * @return void
 */
void student_write_file(std::vector<Student> studentVector, std::string dateiName) {
	if(studentVector.empty()) {
		std::cout << "Die Liste ist leer." << std::endl;
		return;
	}
    std::ofstream datei;
    datei.open(dateiName, std::ios::out);
    
    for(auto it = studentVector.begin(); it != studentVector.end(); ++it) {
        datei << it->getMatNr() << std::endl;
        datei << it->getName() << std::endl;
        datei << it->getGeburtstag() << std::endl;
        datei << it->getAdresse() << std::endl;
    }
}
