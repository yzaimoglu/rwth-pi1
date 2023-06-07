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

/**
     * @brief Search for a city in this map by given name.
     * @param name
     * @return the city pointer, if city not found nullptr
     */
City* Map::findCity(const QString cityName) const {
    // str.compare() --> 0 wenn beide Strings übereinstimmen
    for(auto it = vectorCities.begin(); it != vectorCities.end(); ++it) {
        if(!(*it)->getName().compare(cityName)) {
            return *it;
        }
    }
    return nullptr;
}

/**
     * @brief Search for streets in this map.
     * @param city where you want the street_list from
     * @return A list of all streets in this map connected to provided city.
     */
QVector<Street*> Map::getStreetList(const City* city) const {
    QVector<Street*> connectedStreets;
    QString cityName = city->getName();
    for(auto it = vectorStreets.begin(); it != vectorStreets.end(); ++it)
    {
        City* firstCity = (*it)->getFirstCity();
        City* secondCity = (*it)->getSecondCity();
        // Überprüfen ob einer der Städte der Straße die Straße aus dem Parameter ist
        // Könnte man auch mit einer Operatorüberladung von == machen
        if(!cityName.compare(firstCity->getName()) || !cityName.compare(secondCity->getName()))
        {
            connectedStreets.append(*it);
        }
    }
    return connectedStreets;
}

/**
     * @brief Look for opposite city.
     * @param street
     * @param city
     * @return Opposite city of the street. If city has no connection to street returns nullptr.
     */
City* Map::getOppositeCity(const Street* street, const City* city) const {
    if(!street->getFirstCity()->getName().compare(city->getName())) {
        return street->getSecondCity();
    } else if(!street->getSecondCity()->getName().compare(city->getName())) {
        return street->getFirstCity();
    }
    // Die Straße enthält nicht die Stadt
    return nullptr;
}

/**
     * @brief Calculate the street length.
     * @param street
     * @return Length of the street
     */
double Map::getLength(const Street* street) const {
    double xCoords = street->getSecondCity()->getX() - street->getFirstCity()->getX();
    double yCoords = street->getSecondCity()->getY() - street->getFirstCity()->getY();

    //    qDebug() << xCoords;
    //    qDebug() << yCoords;
    //    qDebug() << sqrt(xCoords * xCoords + yCoords * yCoords);
    return sqrt(xCoords * xCoords + yCoords * yCoords);
}
