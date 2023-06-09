#include "motorway.h"
#include <QDebug>

Motorway::Motorway(City* firstCity, City* secondCity)
    : Street(firstCity, secondCity)
{

}

void Motorway::draw(QGraphicsScene& scene) {
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::darkBlue);
    scene.addLine(this->firstCity->getX(), this->firstCity->getY(), this->secondCity->getX(), this->secondCity->getY(), pen);
    qDebug() << QString("Die Autobahn zwischen den Städten %1 und %2 wurde eingezeichnet.").arg(this->firstCity->getName()).arg(this->secondCity->getName());
}

void Motorway::drawRed(QGraphicsScene& scene) {
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    scene.addLine(this->firstCity->getX(), this->firstCity->getY(), this->secondCity->getX(), this->secondCity->getY(), pen);
    qDebug() << QString("Die Autobahn zwischen den Städten %1 und %2 wurde eingezeichnet.").arg(this->firstCity->getName()).arg(this->secondCity->getName());
}
