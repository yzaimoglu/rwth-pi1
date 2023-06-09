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

    /**
     * @brief Search for a city in this map by given name.
     * @param name
     * @return the city pointer, if city not found nullptr
     */
    City* findCity(const QString cityName) const;

    /**
     * @brief Search for streets in this map.
     * @param city where you want the street_list from
     * @return A list of all streets in this map connected to provided city.
     */
    QVector<Street*> getStreetList(const City* city) const;

    /**
     * @brief Look for opposite city.
     * @param street
     * @param city
     * @return Opposite city of the street. If city has no connection to street returns nullptr.
     */
    City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief Calculate the street length.
     * @param street
     * @return Length of the street
     */
    double getLength(const Street* street) const;

    /**
     * @brief Gibt die Liste der Städte als Zeigervektor zürück
     * @return Liste der Städte als Zeiger
     */
    QVector<City*> getCityList();

    /**
     * @brief Leert die Vektoren
     */
    void clear();
private:
    QVector<City*> vectorCities;
    QVector<Street*> vectorStreets;
};

#endif // MAP_H
