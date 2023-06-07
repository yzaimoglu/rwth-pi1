#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
    QString getName() const;
    int getX();
    int getY();
    bool operator==(const City& city) const;
    bool isSame(QString cityName);

private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
