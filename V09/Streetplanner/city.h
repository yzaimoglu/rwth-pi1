#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
public:
    City(QString name, int x, int y);
    virtual void draw(QGraphicsScene& scene);
    QString getName() const;
    int getX();
    int getY();
    bool operator==(const City& city) const;
    bool isSame(QString cityName);

protected:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
