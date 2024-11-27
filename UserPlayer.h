#ifndef USERPLAYER_H
#define USERPLAYER_H

#include "Player.h"
#include "Coord.h"

class UserPlayer : public Player {
    string username;

    Coord getCoordFromUser() {
        string input;
        int x, y;

        getline(cin, input, ',');
        x = stoi(input);
        getline(cin, input);
        y = stoi(input);

        return Coord(x, y);
    }

    public:
        UserPlayer();
        UserPlayer(Board, string);
        UserPlayer(const UserPlayer&);

        virtual ShotResult makeMove();

        string getUsername();
        void setUsername(string);
};

#endif