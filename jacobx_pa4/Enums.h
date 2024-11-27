#ifndef ENUMS_H
#define ENUMS_H

enum Direction {LEFT, RIGHT, UP, DOWN};
enum ShipType {CARRIER, BATTLESHIP, CRUISER, SUBMARINE, PATROL};
enum ShotResult {SHOT_MISS, SHOT_HIT, SUNK};
enum CoordState {COORD_HIT, COORD_MISS, SHIP};
enum PlayerType {USER, AI};

#endif