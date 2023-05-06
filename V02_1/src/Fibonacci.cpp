/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 2.1: Rekursive Berechnung der Fibonacci-Zahlen
//
// Datei:  Fibonacci.c
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Rekursive Implementierung der Fibonacci-Zahlen
// @param n Wiederholungsvorgangsanzahl
int fibonacci(unsigned int n) {
	// f(0) = 0
	if(n == 0) return 0;
	// f(1) = 1
	else if(n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);;
}

// Fibonacci: n = 0 bis 25
int main() {
	cout << "Berechnung der Fibonacci-Reihe von n = 0 bis 25: " << endl;
	cout << setfill('-') << setw(15) << "" << endl;

	const unsigned int nMax = 25;
	for(int i = 0; i < (nMax + 1); i++) {
		cout << "f(" << i << ") = " << fibonacci(i) << endl;
	}
	return 0;
}



