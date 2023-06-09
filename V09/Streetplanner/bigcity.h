#ifndef BIGCITY_H
#define BIGCITY_H

#include "city.h"

class BigCity : public City
{
public:
    BigCity(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
};

#endif // BIGCITY_H
