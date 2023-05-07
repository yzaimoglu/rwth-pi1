//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	// Nächste Element des aktuell letzten Elements wird zum neuen Element
        back->setNext(neuesElement);
        // Vorherige Element des neuen Elements wird zum aktuell letzten Element
        neuesElement->setPrevious(back);
        // Letztes Element wird zum neuen Element gesetzt
        back = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	// Vorheriges Element des aktuell ersten Elements wird zum neuen Element
        front->setPrevious(neuesElement);
        // Nächstes Element des neuen Elements wird zum aktuell ersten Element
        neuesElement->setNext(front);
        // Erstes Element wird zum neuen Element gesetzt
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)       	                              // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
    	// Zweite Element wird zum ersten Element
        front = front->getNext();
        // Wenn das zweite Element zum ersten wird, muss das vorherige Element zu einem nullptr gesetzt werden
        front->setPrevious(nullptr);
        // Löschen des Anfangselements
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrevious();
    }
}

/*
 * @brief Gibt einen Studenten mit der angegebenen Matrikelnummer zurück
 * @param matNr Die Matrikelnummer des Studenten
 * @return Gibt den Studenten wieder, wenn nicht existierend einen Studenten mit matNr 0
 */
Student Liste::getStudent(unsigned int matNr)
{
	ListenElement* cursor = front;

	while (cursor != nullptr)
	{
		if(cursor->getData().getMatNr() == matNr) return cursor->getData();
		cursor = cursor->getNext();
	}
	return Student();
}

/*
 * @brief Funktion, die einen Studenten aus der Liste mithilfe der Matrikelnummer löscht
 * @param matNr Matrikelnummer des Studenten
 */
void Liste::deleteStudent(unsigned int matNr)
{
	// Cursor erstellen
	ListenElement* cursor = front;

	// Durch die Liste iterieren
	while (cursor != nullptr)
	{
		// Wenn der Student gefunden wird
		if(cursor->getData().getMatNr() == matNr)
		{
			// Wenn es nur diesen Studenten in der Liste gibt
			if (cursor == front && cursor == back)
			{
				// Liste leeren
				front = nullptr;
				back = nullptr;

			}
			// Wenn der Student ganz vorne ist
			else if(cursor == front)
			{
				// Nächstes Element holen
				ListenElement* next = cursor->getNext();
				// Erstes Element zu nächstem Element setzen
				front = next;
				// Vorheriges Element vom nächsten Element zu nullptr setzen
				next->setPrevious(nullptr);
			}
			// Wenn der Student ganz hinten ist
			else if(cursor == back)
			{
				// Vorheriges Element holen
				ListenElement* previous = cursor->getPrevious();
				// Letztes Element zu vorherigem Element setzen
				back = previous;
				// Nächstes Element vom vorherigen Element zu nullptr setzen
				previous->setNext(nullptr);
			}
			// Wenn der Student in der Mitte ist
			else
			{
				// Temporär vorheriges und nächstes Listenelement abspeichern
				ListenElement* previous = cursor->getPrevious();
				ListenElement* next = cursor->getNext();

				// Bei vorherigem Element das nächste Element zum nächsten Element des aktuellen setzen
				previous->setNext(next);
				// Bei nächstem Element das vorherige Element zum vorherigen Element des aktuellen setzen
				next->setPrevious(previous);
			}
			// Student Löschen
			delete cursor;
		}
		cursor = cursor->getNext();
	}
}
