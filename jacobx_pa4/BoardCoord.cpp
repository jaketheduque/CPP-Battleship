#include "BoardCoord.h"

BoardCoord::BoardCoord() : Coord() {};

BoardCoord::BoardCoord(int x, int y, CoordState state) : Coord(x, y) {
    this->state = state;
};

BoardCoord::BoardCoord(const BoardCoord& rhs) : Coord(rhs) {
    state = rhs.state;
};

CoordState BoardCoord::getState() {
    return state;
};

void BoardCoord::setState(CoordState state) {
    this->state = state;
};

ostream& operator <<(ostream& out, const BoardCoord& rhs) {
    out << "(" << rhs.x << "," << rhs.y << "," << rhs.state << ")";
    return out;
};