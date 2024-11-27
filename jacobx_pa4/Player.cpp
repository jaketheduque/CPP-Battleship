#include "Player.h"

Player::Player() {};

Player::Player(Board board, PlayerType type) {
    this->opponentBoard = board;
    this->type = type;
};

Player::Player(const Player& rhs) {
    opponentBoard = rhs.opponentBoard;
    rhs.type;
};


Board& Player::getOpponentBoard() {
    return opponentBoard;
};

PlayerType Player::getType() {
    return type;
};

void Player::setOpponentBoard(Board b) {
    opponentBoard = b;
};

void Player::setType(PlayerType t) {
    type = t;
};