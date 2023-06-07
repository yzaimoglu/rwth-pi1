#include "street.h"

#include <QDebug>

Street::Street(City* firstCity, City* secondCity)
    : firstCity(firstCity), secondCity(secondCity)
{

}

void Street::draw(QGraphicsScene& scene) {
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    scene.addLine(this->firstCity->getX(), this->firstCity->getY(), this->secondCity->getX(), this->secondCity->getY(), pen);
    qDebug() << QString("Die Straße zwischen den Städten %1 und %2 wurde eingezeichnet.").arg(this->firstCity->getName()).arg(this->secondCity->getName());
}

City* Street::getFirstCity() const {
    return this->firstCity;
}

City* Street::getSecondCity() const {
    return this->secondCity;
}
