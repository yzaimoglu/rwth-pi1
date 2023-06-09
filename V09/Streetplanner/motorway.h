#ifndef MOTORWAY_H
#define MOTORWAY_H

#include "street.h"

class Motorway : public Street
{
public:
    Motorway(City* firstCity, City* secondCity);
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene);
};

#endif // MOTORWAY_H
