#include "UserPlayer.h"

UserPlayer::UserPlayer() : Player() {
    type = USER;
};

UserPlayer::UserPlayer(Board board, string username) : Player(board, USER) {
    this->username = username;
};

UserPlayer::UserPlayer(const UserPlayer& rhs) : Player(rhs.opponentBoard, USER) {

};

ShotResult UserPlayer::makeMove() {
    opponentBoard.displayBoard(true);
    cout << "Enter the coordinates of where you would like to fire with X and Y seperated by a comma: ";
    Coord shot = getCoordFromUser();
    ShotResult result = opponentBoard.fireShot(shot);

    return result;
};

string UserPlayer::getUsername() {
    return username;
}

void UserPlayer::setUsername(string username) {
    this->username = username;
}