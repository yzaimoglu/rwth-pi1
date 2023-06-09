#ifndef STATEROAD_H
#define STATEROAD_H

#include "street.h"

class StateRoad : public Street
{
public:
    StateRoad(City* firstCity, City* secondCity);
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene);
};

#endif // STATEROAD_H
