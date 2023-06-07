#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    /**
     * @brief Standardkonstruktor
     */
    Map();

    /**
     * @brief Fügt einen Zeiger auf eine Stadt dem vectorCities hinzu
     * @param city Zeiger auf eine Stadt
     */
    void addCity(City* city);

    /**
     * @brief Fügt einen Zeiger auf eine Straße dem vectorStreets hinzu
     * @param street Zeiger auf eine Straße
     */
    bool addStreet(Street* street);

    /**
     * @brief Zeichnet alle Städte und Straßen
     * @param scene QGraphicsScene auf der gezeichnet werden soll
     */
    void draw(QGraphicsScene& scene);
private:
    QVector<City*> vectorCities;
    QVector<Street*> vectorStreets;
};

#endif // MAP_H
