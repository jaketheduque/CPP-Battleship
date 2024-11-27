#ifndef BOARD_H
#define BOARD_H

#include "DynamicArray.cpp"
#include "Coord.h"
#include "Ship.h"
#include "Enums.h"

class Board {
    DynamicArray<Ship> ships;
    DynamicArray<Coord> attemptedShots;
    DynamicArray<Coord> missedShots;
    int numberShipSpotsLeft;

    Coord getRandomCoord() {
        int x = 1 + ( std::rand() % 10 );
        int y = 1 + ( std::rand() % 10 );

        return Coord(x, y);
    }

    Direction getRandomDirection() {
        int num = std::rand() % 4;

        switch (num) {
            case 0:
                return LEFT;
            case 1:
                return RIGHT;
            case 2:
                return UP;
            case 3:
                return DOWN;
        }

        return LEFT;
    }

    public:
        Board();
        Board(DynamicArray<Ship>);
        Board(const Board&);
        ~Board();

        ShotResult fireShot(Coord);
        bool checkObstruction(Coord, Direction, int);
        void displayBoard(bool opponent=0);
        void generateShips();
        DynamicArray<BoardCoord> getAllShipCoords();

        void addShip(Ship);

        DynamicArray<Ship>& getShips();
        DynamicArray<Coord>& getMissedShots();
        DynamicArray<Coord>& getAttemptedShots();
        int getNumberShipSpotsLeft();
};

#endif