/*
 * Buch.cpp
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#include "Buch.h"

#include "Buch.h"
#include <iostream>


/**
 * @brief Konstruktor mit Parametern
 * @param initTitel Titel
 * @param initAutor Autor
 */
Buch::Buch(std::string initTitel, std::string initAutor)
	: Medium(initTitel), autor(initAutor)
{
}

/**
 * @brief Standarddestruktor
 */
Buch::~Buch()
{
}

/**
 * @brief Ausgabefunktion mit Vererbung aus Basisklasse Medium
 */
void Buch::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "Autor: " << this->autor <<std::endl;
}

