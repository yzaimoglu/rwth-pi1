#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
public:
    Street(City* firstCity, City* secondCity);
    void draw(QGraphicsScene& scene);
    City* getFirstCity() const;
    City* getSecondCity() const;
private:
    City* firstCity;
    City* secondCity;
};

#endif // STREET_H
