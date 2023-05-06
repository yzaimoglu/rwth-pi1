//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 02
//
// Datei:  fibonacci.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

/*
 * Zu UP3
 * Bei n = 42 ist die rekursive Variante langsamer, da die Implementierung O(n) = 2^n ist.
 * Bei jedem Aufruf werden zwei weitere Aufrufe der Funktion gestartet --> exp. Wachstum des Funktionsstacks.
 * Bei der iterativen Variante ist die Implementierung O(n) = n, da keine weiteren Funktionen aufgerufen werden.
 * --> Rekursionen sind mit Vorsicht zu genießen.
 */

/*
 * Zu UP4
 * Bei n = 47 ist das errechnete Ergebnis falsch, da int eine 32bit Zahl darstellt.
 * Das heißt, dass unsere Funktionen nur bis zu einem Aufruf von f(i) <= 2^32 funktionieren.
 * Diese Zahl ist bei n = 47 erreicht.
 * Man könnte das ganze beheben, indem man die Funktion mit dem Typ long long umschreibt.
 * char = 8bit
 * short = 16bit
 * int = 16bit (kann aber auch 32bit sein)
 * long = 32bit (kann aber auch 64bit sein)
 * long long = 64bit
 * Diese Zahlenlimits hängen von der Prozessorarchitektur ab.
 */

// UP2
int fibonacci(int n) {
	// 1 --> 0 (Startzahl = 0)
    int previousFib = 0;
    int currentFib = 1;

    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    // Anpassung der Schleife, da die Schleife nur bis n - 2 laufen soll
    // also n --> (n-2)
    for (int i = 0; i <= (n - 2); i++) {
        int newFib = previousFib + currentFib;
        // newFib --> currentFib
        previousFib = currentFib;
        // previousFib --> newFib
        currentFib = newFib;
    }

    return currentFib;
}

int main () {
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl;
    for (int i = 1; i <= 12 ; i ++) {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl;
    }
    return 0;
}
