#include "map.h"
#include <QDebug>

Map::Map()
{

}

void Map::addCity(City* city) {
    vectorCities.append(city);
    qDebug() << QString("Die Stadt %1 wurde der Map hinzugefügt.").arg(city->getName());
}

bool Map::addStreet(Street* street) {
    if(!vectorCities.contains(street->getFirstCity()) || !vectorCities.contains(street->getSecondCity())) {
        qDebug() << QString("Einer der angegebenen Städte %1 und %2 sind nicht auf der Map.").arg(street->getFirstCity()->getName()).arg(street->getSecondCity()->getName());
        return false;
    }
    vectorStreets.append(street);
    qDebug() << QString("Die Straße zwischen den Städten %1 und %2 wurde der Map hinzugefügt.").arg(street->getFirstCity()->getName()).arg(street->getSecondCity()->getName());
    return true;
}

void Map::draw(QGraphicsScene& scene) {
    // Nutzung von for each eig. auch möglich
    //    foreach (City* city, vectorCities) {
    //        city->draw(scene);
    //    }
    for(auto it = vectorCities.begin(); it != vectorCities.end(); ++it) {
        (*it)->draw(scene);
    }

    for(auto it = vectorStreets.begin(); it != vectorStreets.end(); ++it) {
        (*it)->draw(scene);
    }
}
