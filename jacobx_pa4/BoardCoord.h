#ifndef BOARDCOORD_H
#define BOARDCOORD_H

#include "Coord.h"
#include "Enums.h"

class BoardCoord : public Coord {
    CoordState state;

    public:
        BoardCoord();
        BoardCoord(int, int, CoordState);
        BoardCoord(const BoardCoord&);

        CoordState getState();
        void setState(CoordState);

        friend ostream& operator <<(ostream&, const BoardCoord&);
};

#endif