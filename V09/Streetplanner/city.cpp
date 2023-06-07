#include "city.h"
#include <QString>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y)
    : name(name), x(x), y(y)
{

}

void City::draw(QGraphicsScene& scene) {
    scene.addEllipse(this->getX(), this->getY(), 10, 10, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem* cityName = new QGraphicsTextItem;
    cityName->setPos(this->getX(), this->getY());
    cityName->setPlainText(this->getName());

    scene.addItem(cityName);
    qDebug() << QString("Die Stadt %1 wurde in der Position x:%2, y:%3 gezeichnet.").arg(this->getName()).arg(this->getX()).arg(this->getY());
}

QString City::getName() {
    return this->name;
}

int City::getX() {
    return this->x;
}

int City::getY() {
    return this->y;
}
