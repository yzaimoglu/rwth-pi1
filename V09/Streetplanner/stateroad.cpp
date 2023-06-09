#include "stateroad.h"
#include <QDebug>

StateRoad::StateRoad(City* firstCity, City* secondCity)
    : Street(firstCity, secondCity)
{

}

void StateRoad::draw(QGraphicsScene& scene) {
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::darkGray);
    scene.addLine(this->firstCity->getX(), this->firstCity->getY(), this->secondCity->getX(), this->secondCity->getY(), pen);
    qDebug() << QString("Die Landstraße zwischen den Städten %1 und %2 wurde eingezeichnet.").arg(this->firstCity->getName()).arg(this->secondCity->getName());
}

void StateRoad::drawRed(QGraphicsScene& scene) {
    QPen pen;
    pen.setWidth(4);
    pen.setColor(Qt::red);
    scene.addLine(this->firstCity->getX(), this->firstCity->getY(), this->secondCity->getX(), this->secondCity->getY(), pen);
    qDebug() << QString("Die Landstraße zwischen den Städten %1 und %2 wurde eingezeichnet.").arg(this->firstCity->getName()).arg(this->secondCity->getName());
}
