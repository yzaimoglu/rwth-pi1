#include <QGraphicsTextItem>
#include "bigcity.h"

BigCity::BigCity(QString name, int x, int y)
    : City(name, x, y)
{

}

void BigCity::draw(QGraphicsScene& scene) {
    scene.addEllipse(this->getX(), this->getY(), 10, 10, QPen(Qt::blue, 3), QBrush(Qt::blue, Qt::SolidPattern));

    QGraphicsTextItem* cityName = new QGraphicsTextItem;
    cityName->setPos(this->getX(), this->getY());
    cityName->setPlainText(this->getName());

    scene.addItem(cityName);
    qDebug() << QString("Die Großstadt %1 wurde in der Position x:%2, y:%3 gezeichnet.").arg(this->getName()).arg(this->getX()).arg(this->getY());
}
