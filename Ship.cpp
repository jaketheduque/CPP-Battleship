#include "Ship.h"

#include <iostream>

Ship::Ship() {
    hitpoints = -1;
    size = -1;
};

Ship::Ship(Coord head, Direction direction, ShipType type) {
    this->type = type;

    int size;
    switch(type) {
        case CARRIER: 
            size = 5;
            break;
        case BATTLESHIP:
            size = 4;
            break;
        case CRUISER:
            size = 3;
            break;
        case SUBMARINE:
            size = 3;
            break;
        case PATROL:
            size = 2;
            break;
    }
    this->size = size;
    hitpoints = size;

    switch(direction) {
        case LEFT:
            for (int i = 0 ; i < size ; i++) {
                coords.add(BoardCoord(head.getX()-i, head.getY(), SHIP));
            }
            break;
        case RIGHT:
            for (int i = 0 ; i < size ; i++) {
                coords.add(BoardCoord(head.getX()+i, head.getY(), SHIP));
            }
            break;
        case DOWN:
            for (int i = 0 ; i < size ; i++) {
                coords.add(BoardCoord(head.getX(), head.getY()-i, SHIP));
            }
            break;
        case UP:
            for (int i = 0 ; i < size ; i++) {
                coords.add(BoardCoord(head.getX(), head.getY()+i, SHIP));
            }
            break;            
    }
};

Ship::Ship(const Ship& rhs) {
    coords = rhs.coords;
    size = rhs.size;
    hitpoints = rhs.hitpoints;
    type = rhs.type;
};

Ship::~Ship() {
    
}

int Ship::getHitpoints() {
    return hitpoints;
};

int Ship::getSize() {
    return size;
}

ShipType Ship::getType() {
    return type;
}

DynamicArray<BoardCoord> Ship::getCoords() {
    return coords;
};

void Ship::setHitpoints(int hitpoints) {
    this->hitpoints = hitpoints;
};

void Ship::setCoords(DynamicArray<BoardCoord> coords) {
    this->coords = coords;
};

ShotResult Ship::fireShot(Coord shot) {
    for (int i = 0 ; i < coords.getSize() ; i++) {
        if (coords.get(i) == shot) {
            hitpoints--;
            coords.get(i).setState(COORD_HIT);

            if (hitpoints == 0) {
                return SUNK;
            } else {
                return SHOT_HIT;
            }
        }
    }

    return SHOT_MISS;
};