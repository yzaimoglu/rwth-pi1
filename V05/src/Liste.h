//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void pushFront(Student pData);
    void popFront();
    bool empty();
    Student dataFront();
    Student getStudent(unsigned int matNr);
    void deleteStudent(unsigned int matNr);
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;
};

#endif /*LISTE_H_*/
