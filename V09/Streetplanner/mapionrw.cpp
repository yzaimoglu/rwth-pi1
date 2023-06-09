///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#include "mapionrw.h"
#include "smallcity.h"
#include "bigcity.h"
#include "motorway.h"
#include "stateroad.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new SmallCity("Aachen", -100, 100);
    City* bonn = new BigCity("Bonn", 0,200);
    City* koeln = new City("Köln", 0,0);
    City* duesseldorf = new City("Düsseldorf", 50,-100);

    Street* aachenKoeln = new Motorway(aachen, koeln);
    Street* bonnKoeln = new Street(bonn, koeln);
    Street* ddorfKoeln = new StateRoad(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addStreet(aachenKoeln);
    map.addStreet(bonnKoeln);
    map.addStreet(ddorfKoeln);
}
