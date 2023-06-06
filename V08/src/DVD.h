/*
 * DVD.h
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

/**
 * @brief Subklasse DVD der Basisklasse Medium
 */
class DVD: public Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

	virtual ~DVD();

	void ausgabe() const;

	bool ausleihen(Person person, Datum ausleihdatum);
protected:
	int altersFreigabe;
	std::string genre;
};

#endif /* DVD_H_ */
