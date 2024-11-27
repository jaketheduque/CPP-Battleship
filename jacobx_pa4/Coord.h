#ifndef COORD_H
#define COORD_H

#include <iostream>

using namespace std;

class Coord {
    protected:
        int x, y;

    public:
        Coord();
        Coord(int, int);
        Coord(const Coord&);

        int getX();
        int getY();

        bool operator ==(const Coord&);
        friend ostream& operator <<(ostream&, const Coord&);
};

#endif