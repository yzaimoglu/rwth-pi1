/*
 * Buch.h
 *
 *  Created on: 6 Jun 2023
 *      Author: yagi
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium
{
	public:
		Buch(std::string initTitel, std::string initAutor);

		virtual ~Buch();

		void ausgabe() const;
	protected:
		std::string autor;
};

#endif /* BUCH_H_ */
