#ifndef SHIP_H
#define SHIP_H

#include "BoardCoord.h"
#include "DynamicArray.cpp"
#include "Enums.h"

class Ship {
    int hitpoints, size;
    DynamicArray<BoardCoord> coords;
    ShipType type;

    public:
        Ship();
        Ship(Coord, Direction, ShipType);
        Ship(const Ship&);
        ~Ship();

        int getHitpoints();
        int getSize();
        DynamicArray<BoardCoord> getCoords();
        ShipType getType();

        void setHitpoints(int);
        void setCoords(DynamicArray<BoardCoord>);
        void setType(ShipType);

        ShotResult fireShot(Coord);
};

#endif