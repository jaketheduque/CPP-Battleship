#include "AIPlayer.h"

AIPlayer::AIPlayer() : Player() {
    type = AI;
};

AIPlayer::AIPlayer(Board board) : Player(board, AI) {

};

AIPlayer::AIPlayer(const AIPlayer& rhs) : Player(rhs.opponentBoard, AI) {

};

ShotResult AIPlayer::makeMove() {
    Coord fire;

    bool alreadyFired;

    if (lastHitResult == SHOT_HIT) {
        int attemptsLeft = 4;
        Direction direction = getRandomDirection();

        while (attemptsLeft > 0) {
            int fireX = lastHit.getX();
            int fireY = lastHit.getY();

            switch (direction) {
                case LEFT:
                    fireX--;
                    break;
                case RIGHT:
                    fireX++;
                    break;
                case UP:
                    fireY++;
                    break;
                case DOWN:
                    fireY--;
                    break;
            }

            fire = Coord(fireX, fireY);

            if (opponentBoard.getAttemptedShots().exists(fire)) {
                attemptsLeft--;
                continue;
            } else {
                ShotResult result = opponentBoard.fireShot(fire);

                if (result == SHOT_HIT || result == SUNK) {
                    lastHit = fire;
                    lastHitResult = result;
                }

                return result;
            }
        }
    } 

    do {
        fire = getRandomCoord();
        alreadyFired = opponentBoard.getAttemptedShots().exists(fire);
    } while (alreadyFired);

    ShotResult result = opponentBoard.fireShot(fire);

    if (result == SHOT_HIT || result == SUNK) {
        lastHit = fire;
        lastHitResult = result;
    }

    return result;
};

Coord AIPlayer::getLastHit() {
    return lastHit;    
};

ShotResult AIPlayer::getLastHitResult() {
    return lastHitResult;
};

void AIPlayer::setLastHit(Coord coord) {
    lastHit = coord;
};

void AIPlayer::setLastHitResult(ShotResult result) {
    lastHitResult = result;
};
