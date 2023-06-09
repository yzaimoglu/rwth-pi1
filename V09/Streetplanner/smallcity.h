#ifndef SMALLCITY_H
#define SMALLCITY_H

#include "city.h"

class SmallCity : public City
{
public:
    SmallCity(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
};

#endif // SMALLCITY_H
