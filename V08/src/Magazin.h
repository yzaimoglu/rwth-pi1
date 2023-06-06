/*
 * Magazin.h
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin: public Medium
{
public:
		Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

		virtual ~Magazin();

		void ausgabe() const;

		bool ausleihen(Person person, Datum ausleihdatum);

	protected:
		Datum ausgabeDatum;
		std::string sparte;
};


#endif /* MAGAZIN_H_ */
