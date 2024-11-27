#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Coord.h"

class AIPlayer : public Player {
    Coord lastHit;
    ShotResult lastHitResult;

    public:
        AIPlayer();
        AIPlayer(Board);
        AIPlayer(const AIPlayer&);

        virtual ShotResult makeMove();

        Coord getLastHit();
        ShotResult getLastHitResult();
        void setLastHit(Coord);
        void setLastHitResult(ShotResult);
};

#endif