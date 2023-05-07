//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define PI 3.1415926536

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Funktion, die die Komponente des Vektors ausgibt
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/*
 * @brief Funktion, die die Länge des Vektors zurückgibt
 * @return Länge des Vektors
 */
double Vektor::laenge() const
{
	return sqrt(x * x + y * y + z * z);
}

/*
 * @brief Funktion, die zwei Vektoren subtrahiert
 * @param input Zu subtrahierender Vektor
 * @return Ergebnisvektor
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(x - input.x, y - input.y, z - input.z);
}

/*
 * @brief Funktion, die das Skalarprodukt zweier Vektoren berechnet
 * @param input Zweiter Vektor
 * @return Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return (x * input.x + y * input.y + z * input.z);
}

/*
 * @brief Funktion, die den Winkel zwischen zwei Vektoren berechnet
 * @param input Zweiter Vektor
 * @return Winkel zwischen den Vektoren
 */
double Vektor::winkel(const Vektor& input) const
{
	return acos(skalarProd(input) / (laenge() * input.laenge())) * 180 / PI;
}

/*
 * @brief Funktion, die einen Vektor um die z-Achse rotiert
 * @param rad Winkelgrad in rad für die Rotation
 */
void Vektor::rotiereUmZ(const double rad)
{
	const double tempX = x;
	const double tempY = y;
	const double tempZ = z;
	const double rotMat[3][3] =
	{
		{cos(rad), -sin(rad), 0},
		{sin(rad), cos(rad), 0},
		{0, 0, 1}
	};

	x = tempX * rotMat[0][0] + tempY * rotMat[0][1] + tempZ * rotMat[0][2];
	y = tempX * rotMat[1][0] + tempY * rotMat[1][1] + tempZ * rotMat[1][2];
	z = tempX * rotMat[2][0] + tempY * rotMat[2][1] + tempZ * rotMat[2][2];
}
