#include "Coord.h"

Coord::Coord() {
    this->x = -1;
    this->y = -1;
}

Coord::Coord(int x, int y) {
    this->x = x;
    this->y = y;
};

Coord::Coord(const Coord& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
};

int Coord::getX() {
    return x;
}

int Coord::getY() {
    return y;
}

bool Coord::operator ==(const Coord& rhs) {
    if (rhs.x == x && rhs.y == y) {
        return true;
    } else {
        return false;
    }
}

ostream& operator <<(ostream& out, const Coord& rhs) {
    out << "(" << rhs.x << "," << rhs.y << ")";
    return out;
};