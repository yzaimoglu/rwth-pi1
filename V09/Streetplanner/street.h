#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
public:
    Street(City* firstCity, City* secondCity);
    virtual void draw(QGraphicsScene& scene);
    virtual void drawRed(QGraphicsScene& scene);
    City* getFirstCity() const;
    City* getSecondCity() const;
protected:
    City* firstCity;
    City* secondCity;
};

#endif // STREET_H
