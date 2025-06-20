/**
 * Praktikum Informatik 1 MMXXIII
 *
 * @file reversi.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	// X Position darf nicht kleiner als 0 oder groesser als die GROESSE_X sein
	if(posX >= 0 && posX < GROESSE_X)
	{
		// Y Position darf nicht kleiner als 0 oder groesser als die GROESSE_Y sein
		if(posY >= 0 && posY < GROESSE_Y) {
			return true;
		}
	}
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
        	// Gegnerischer Stein in benachbartem Feld?
        	if(aufSpielfeld(posX + j, posY + i) && spielfeld[posY + i][posX + j] == gegner) {
        		// Weitere Untersuchung in gleiche Richtung
        		int naechsteY = 2 * i;
        		int naechsteX = 2 * j;
        		// Weitermachen bis Spielfeldrand erreicht wird oder leeres Feld gefunden wird
        		// 0 = leeres Feld
        		while(aufSpielfeld(posX + naechsteX, posY + naechsteY) && spielfeld[posY + naechsteY][posX + naechsteX] != 0) {
        			if(spielfeld[posY + naechsteY][posX + naechsteX] == aktuellerSpieler) {
        				return true;
        			}
        			naechsteY += i;
        			naechsteX += j;
        		}
        	}
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    // Spielfeld sollte leer sein
    if (spielfeld[posY][posX] != 0) {
    	return;
    }

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...
			// Gegnerischer Stein in benachbartem Feld?
			if(aufSpielfeld(posX + j, posY + i) && spielfeld[posY + i][posX + j] == gegner) {
				// Weitere Untersuchung in gleiche Richtung
				int naechsteY = i;
				int naechsteX = j;

				// durchgefuehrt zeigt an, wie viele Felder geaendert werden sollen
				int durchgefuehrt = 0;

				// Weitermachen bis Spielfeldrand erreicht wird oder leeres Feld gefunden wird
				// 0 = leeres Feld
				while(aufSpielfeld(posX + naechsteX, posY + naechsteY) && spielfeld[posY + naechsteY][posX + naechsteX] != 0) {
					durchgefuehrt++;
					if(spielfeld[posY + naechsteY][posX + naechsteX] == aktuellerSpieler) {
						// Ändern der Felder
						for(int k = 1; k < durchgefuehrt; k++) {
							spielfeld[posY + i * k][posX + j * k] = aktuellerSpieler;
						}

						spielfeld[posY][posX] = aktuellerSpieler;
						// Nachdem alle Steine geändert wurden, kann mit der while-Loop aufgehört werden
						break;
					}
					naechsteY += i;
					naechsteX += j;
				}
			}
        }
    }

}

/**
 * @brief Funktion, die Anzahl der möglichen Zuege liefert
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return Anzahl moeglicher Zuege
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
    int moeglicheZuge = 0;
    for(int posY = 0; posY < GROESSE_Y; posY++) {
    	for(int posX = 0; posX < GROESSE_X; posX++) {
    		if(zugGueltig(spielfeld, aktuellerSpieler, posX, posY)) {
    			moeglicheZuge++;
    		}
    	}
    }
    return moeglicheZuge;
}

/**
 * @brief Funktion führt einen menschlichen Zug aus
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return true wenn ein der Zug ausgeführt wurde, false wenn keine möglichen Züge für den Spieler da sind
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}


/**
 * @brief Funktion, zum Spielen
 *
 * @param spielerTyp Array des Spielertyps
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while(moeglicheZuege(spielfeld, aktuellerSpieler) || moeglicheZuege(spielfeld, 3 - aktuellerSpieler)) {
    	// Aussetzen des Spielers, wenn kein Zug für den Spieler vorhanden ist
    	if(moeglicheZuege(spielfeld, aktuellerSpieler)) {
    		std::cout << "Spielzug von SPIELER " << aktuellerSpieler << ": " << std::endl;
    		if(spielerTyp[aktuellerSpieler - 1] == MENSCH) menschlicherZug(spielfeld, aktuellerSpieler);
    		else computerZug(spielfeld, aktuellerSpieler);
    		zeigeSpielfeld(spielfeld);
    	}

    	// Spieler wird zum Gegner
    	aktuellerSpieler = 3 - aktuellerSpieler;
    }

    // Gewinnerbekanntgabe
    switch (gewinner(spielfeld))
    {
		case 1:
			std::cout << "SPIELER 1 hat gewonnen!" << std::endl;
			break;
		case 2:
			std::cout << "SPIELER 2 hat gewonnen!" << std::endl;
			break;
    }
    // ODER: std::cout << "SPIELER " << gewinner(spielfeld) << " hat gewonnen!" << std::endl;
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    //    int spielfeld[GROESSE_Y][GROESSE_X];
    //
    //    initialisiereSpielfeld(spielfeld);
    //
    //    zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    bool weiterspielen = 1;
    do {
    	int spielerTyp[2];
		int spielerTypAuswahl[2];

		// Spieler 1 Typauswahl
		std::cout << "Soll Spieler 1 ein Computer sein? " << std::endl << "Wenn ja bitte 1 eingeben." << std::endl;
		std::cin >> spielerTypAuswahl[0];
		if(spielerTypAuswahl[0]) spielerTyp[0] = COMPUTER;
		else spielerTyp[0] = MENSCH;

		// Spieler 2 Typauswahl
		std::cout << "Soll Spieler 2 ein Computer sein? " << std::endl << "Wenn ja bitte 1 eingeben." << std::endl;
		std::cin >> spielerTypAuswahl[1];
		if(spielerTypAuswahl[1]) spielerTyp[1] = COMPUTER;
		else spielerTyp[1] = MENSCH;

		// Beginn des Spiels
		std::cout << "Das Spiel beginnt" << std::endl;
		spielen(spielerTyp);

		// Weiterspielaufforderung
		std::cout << "Möchtest du weiter spielen?" << std::endl;
		std::cout << "Wenn ja bitte gebe 1 ein." << std::endl;
		std::cin >> weiterspielen;
    } while(weiterspielen);

    std::cout << "Danke fürs Mitspielen!" << std::endl;
    return 0;
}
