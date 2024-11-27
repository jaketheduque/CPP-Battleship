#include "Board.h"

Board::Board() {
    this->numberShipSpotsLeft = 0;
};

Board::Board(DynamicArray<Ship> ships) {
    this->ships = ships;
    this->numberShipSpotsLeft = 0;

    for (int i = 0 ; i < this->ships.getSize() ; i++) {
        numberShipSpotsLeft += this->ships.get(i).getHitpoints();
    }
};

Board::Board(const Board& rhs) {
    this->ships = rhs.ships;
    this->attemptedShots = rhs.attemptedShots;
    this->numberShipSpotsLeft = rhs.numberShipSpotsLeft;
};

Board::~Board() {}

ShotResult Board::fireShot(Coord coord) {
    attemptedShots.add(coord);

    for (int i = 0 ; i < ships.getSize() ; i++) {
        ShotResult result = ships.get(i).fireShot(coord);
        
        if (result == SHOT_HIT || result == SUNK) {
            numberShipSpotsLeft--;
            return result;
        }
    }

    missedShots.add(coord);
    return SHOT_MISS;
};

bool Board::checkObstruction(Coord coord, Direction direction, int distance) {
    DynamicArray<BoardCoord> shipCoords = getAllShipCoords();
    int checkX = coord.getX();
    int checkY = coord.getY();

    if (checkX > 10 || checkX < 1 || checkY > 10 || checkY < 1) {
        return true;
    }

    if (shipCoords.exists(BoardCoord(checkX, checkY, COORD_MISS))) {
        return true;
    }

    for (int i = 0 ; i < distance-1 ; i++) {
        switch (direction) {
            case LEFT:
                checkX--;
                break;
            case RIGHT:
                checkX++;
                break;
            case UP:
                checkY++;
                break;
            case DOWN:
                checkY--;
                break;
        }

        if (checkX > 10 || checkX < 1 || checkY > 10 || checkY < 1) {
            return true;
        }

        if (shipCoords.exists(BoardCoord(checkX, checkY, COORD_MISS))) {
            return true;
        }
    }

    return false;
};

void Board::displayBoard(bool opponent) {
    char board[10][10];

    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            board[i][j] = '-';
        }
    }

    for (int i = 0 ; i < missedShots.getSize() ; i++) {
        Coord coord = missedShots.get(i);

        board[coord.getX()-1][coord.getY()-1] = 'M';
    }

    for (int i = 0 ; i < ships.getSize() ; i++) {
        Ship ship = ships.get(i);
        char shipChar;

        switch (ship.getType()) {
            case CARRIER:
                shipChar = 'C';
                break;
            case BATTLESHIP:
                shipChar = 'B';
                break;
            case CRUISER:
                shipChar = 'c';
                break;
            case SUBMARINE:
                shipChar = 'S';
                break;
            case PATROL:
                shipChar = 'P';
                break;
        }

        for (int j = 0 ; j < ship.getCoords().getSize() ; j++) {
            BoardCoord coord = ship.getCoords().get(j);

            if (coord.getState() == COORD_HIT) {
                board[coord.getX()-1][coord.getY()-1] = '*';
            } else {
                if (!opponent) {
                    board[coord.getX()-1][coord.getY()-1] = shipChar;
                }
            }
        }
    }

    for (int i = 9 ; i >= 0 ; i--) {
        if (i == 9) {
            cout << "10 ";
        } else {
            cout << " " << i+1 << " ";
        }

        for (int j = 0 ; j < 10 ; j++) {
            cout << board[j][i];

            if (j != 9) {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << " . 1 2 3 4 5 6 7 8 9 10" << endl;
};

void Board::generateShips() {
    Direction direction = getRandomDirection();
    Coord head = getRandomCoord();
    bool obstructed;

    do {
        obstructed = checkObstruction(head, direction, 5);

        if (!obstructed) {
            Ship ship = Ship(head, direction, CARRIER);
            addShip(ship);
            break;
        }

        direction = getRandomDirection();
        head = getRandomCoord();
    } while (obstructed == true);

    do {
        obstructed = checkObstruction(head, direction, 4);

        if (!obstructed) {
            Ship ship = Ship(head, direction, BATTLESHIP);
            addShip(ship);
            break;
        }

        direction = getRandomDirection();
        head = getRandomCoord();
    } while (obstructed == true);

    do {
        obstructed = checkObstruction(head, direction, 3);

        if (!obstructed) {
            Ship ship = Ship(head, direction, SUBMARINE);
            addShip(ship);
            break;
        }

        direction = getRandomDirection();
        head = getRandomCoord();
    } while (obstructed == true);

    do {
        obstructed = checkObstruction(head, direction, 3);

        if (!obstructed) {
            Ship ship = Ship(head, direction, CRUISER);
            addShip(ship);
            break;
        }

        direction = getRandomDirection();
        head = getRandomCoord();
    } while (obstructed == true);

    do {
        obstructed = checkObstruction(head, direction, 2);

        if (!obstructed) {
            Ship ship = Ship(head, direction, PATROL);
            addShip(ship);
            break;
        }

        direction = getRandomDirection();
        head = getRandomCoord();
    } while (obstructed == true);
};

DynamicArray<BoardCoord> Board::getAllShipCoords() {
    DynamicArray<BoardCoord> all;

    for (int i = 0 ; i < ships.getSize() ; i++) {
        all.add(ships.get(i).getCoords());
    }

    return all;
};

void Board::addShip(Ship s) {
    ships.add(s);

    numberShipSpotsLeft += s.getSize();
}

DynamicArray<Ship>& Board::getShips() {
    return ships;
};

DynamicArray<Coord>& Board::getMissedShots() {
    return missedShots;
};

DynamicArray<Coord>& Board::getAttemptedShots() {
    return attemptedShots;
}

int Board::getNumberShipSpotsLeft() {
    return numberShipSpotsLeft;
};
