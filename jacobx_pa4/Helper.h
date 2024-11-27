#ifndef HELPER_H
#define HELPER_H

#include "Enums.h"
#include "Board.h"

int getSizeFromShipType(ShipType type) {
    switch (type) {
        case CARRIER:
            return 5;
        case BATTLESHIP:
            return 4;
        case CRUISER:
            return 3;
        case SUBMARINE:
            return 3;
        case PATROL:
            return 2;
    }

    return -1;
}

ShipType getNextShipType(ShipType type) {
    switch (type) {
        case CARRIER:
            return BATTLESHIP;
        case BATTLESHIP:
            return CRUISER;
        case CRUISER:
            return SUBMARINE;
        case SUBMARINE:
            return PATROL;
        case PATROL:
            return CARRIER;
    }

    return CARRIER;
}

Board createBoardFromUserInput() {
    Board b;
    int x, y, selection;
    ShipType type = CARRIER;
    Coord coord;
    Direction direction;
    string junk, input;
    int shipsCreated = 0;

    char randomBoard;
    cout << "Would you like to generate a random board? Type Y or N: ";
    cin >> randomBoard;
    getchar();

    if (randomBoard == 'Y' || randomBoard == 'y') {
        b.generateShips();

        system("clear");
        cout << "Board has been generated!" << endl;
        b.displayBoard();
        cout << "Press enter to continue...";
        getchar();

        return b;
    }

    while (shipsCreated < 5) {
        b.displayBoard();
        
        switch (type) {
            case CARRIER:
                cout << "Enter the starting location for your Carrier with X and Y seperated by a comma: ";
                break;
            case BATTLESHIP:
                cout << "Enter the starting location for your Battleship with X and Y seperated by a comma: ";
                break;
            case CRUISER:
                cout << "Enter the starting location for your Cruiser with X and Y seperated by a comma: ";
                break;
            case SUBMARINE:
                cout << "Enter the starting location for your Submarine with X and Y seperated by a comma: ";
                break;
            case PATROL:
                cout << "Enter the starting location for your Patrol Boat with X and Y seperated by a comma: ";
                break;
        }

        getline(cin, input, ',');
        x = stoi(input);
        getline(cin, input);
        y = stoi(input);
        coord = Coord(x, y);

        bool valid = false;

        cout << "1) Left\n2) Right\n3) Up\n4) Down" << endl;

        do {
            cout << "Choose a direction:" << endl;
            cin >> selection;
            getchar();

            switch (selection) {
                case 1:
                    direction = LEFT;
                    break;
                case 2:
                    direction = RIGHT;
                    break;
                case 3:
                    direction = UP;
                    break;
                case 4:
                    direction = DOWN;
                    break;
                default:
                    direction = LEFT;
                    break;
            }

            if (b.checkObstruction(coord, direction, getSizeFromShipType(type))) {
                cout << "Ship does not fit! Please choose a different direction" << endl;
            } else {
                valid = true;

                Ship ship = Ship(coord, direction, type);
                b.addShip(ship);

                shipsCreated++;

                type = getNextShipType(type);
            }
        } while (!valid);    
    }

    return b;
}

int startGameFromMainMenu() {
    int selection;
    
    cout << "------------------ Battleship ------------------" << endl;
    cout << "1) Play against AI" << endl;
    cout << "2) Play against another player" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose one of the options from above: ";
    
    cin >> selection;
    getchar();

    return selection;
}

string getUsernameFromConsole() {
    string username;

    cout << "Enter a username with no spaces: ";
    cin >> username;
    getchar();

    return username;
}

#endif