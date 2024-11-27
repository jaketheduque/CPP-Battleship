#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Enums.h"

class Player {
    protected:
        Board opponentBoard;
        PlayerType type;

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
        Player();
        Player(Board, PlayerType);
        Player(const Player&);

        virtual ShotResult makeMove() = 0;

        Board& getOpponentBoard();
        PlayerType getType();

        void setOpponentBoard(Board);
        void setType(PlayerType);
};

#endif