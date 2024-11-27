#include <iostream>

#include "DynamicArray.cpp"
#include "BoardCoord.h"
#include "Board.h"
#include "Ship.h"
#include "Helper.h"
#include "AIPlayer.h"
#include "UserPlayer.h"

using namespace std;

int main() {
    srand(time(NULL));

    system("clear");
    int mainMenu = startGameFromMainMenu();
    system("clear");

    Player* currentPlayer;
    Player* waitingPlayer;
    Player* loser = nullptr;

    if (mainMenu == 1) { // Start game against AI
        string username = getUsernameFromConsole();
        system("clear");
        Board board = createBoardFromUserInput();
        system("clear");
        cout << username << " has been initialized!" << endl;
        cout << "Press enter to continue...";
        getchar();

        Board computerBoard;
        computerBoard.generateShips();

        UserPlayer player = UserPlayer(computerBoard, username);
        AIPlayer computer = AIPlayer(board);

        system("clear");
        if (rand() % 2 == 0) {
            cout << "You will start first!" << endl;
            currentPlayer = &player;
            waitingPlayer = &computer;
        } else {
            cout << "The computer will start first!" << endl;
            currentPlayer = &computer;
            waitingPlayer = &player;
        }

        cout << "Press enter to continue...";
        getchar();
        system("clear");

        while (loser == nullptr) {
            ShotResult result;
            
            if (currentPlayer == &player) { // Player makes a move
                do {
                    result = currentPlayer->makeMove();

                    if (currentPlayer->getOpponentBoard().getNumberShipSpotsLeft() == 0) {
                        cout << player.getUsername();
                        loser = &computer;
                        cout << " has won the game!" << endl;
                        break;
                    }

                    if (loser) {
                        break;
                    }

                    system("clear");
                    
                    switch (result) {
                        case SUNK:
                            cout << "Ship sunk! Make another move" << endl;
                            break;
                        case SHOT_HIT:
                            cout << "Hit! Make another move" << endl;
                            break;
                        case SHOT_MISS:
                            currentPlayer->getOpponentBoard().displayBoard(true);
                            cout << "Miss!" << endl;
                            break;
                    }
                } while (result != SHOT_MISS);

                cout << "Press enter to have the computer make a move...";
                getchar();
                system("clear");
            } else { // Computer makes a move
                do {
                    result = currentPlayer->makeMove();

                    if (currentPlayer->getOpponentBoard().getNumberShipSpotsLeft() == 0) {
                        loser = &player;
                        cout << "The computer has won the game!" << endl;
                        break;
                    }

                    if (loser) {
                        break;
                    }

                    system("clear");
                    currentPlayer->getOpponentBoard().displayBoard();
                    
                    switch (result) {
                        case SUNK:
                            cout << "The AI sunk a ship! Press enter for the AI to make another move...";
                            break;
                        case SHOT_HIT:
                            cout << "The AI hit a ship! Press enter for the AI to make another move...";
                            break;
                        case SHOT_MISS:
                            cout << "The AI missed! Press enter to continue...";
                            break;
                    } 

                    getchar();
                    system("clear");                    
                } while (result != SHOT_MISS);
            } 

            Player* temp = currentPlayer;
            currentPlayer = waitingPlayer;
            waitingPlayer = temp;
        }
    }

    if (mainMenu == 2) { // Start game against another player
        string username1 = getUsernameFromConsole();
        system("clear");
        Board board1 = createBoardFromUserInput();
        system("clear");
        cout << username1 << " has been initialized. Pass the computer to other player now" << endl;
        cout << "Press enter to continue...";
        getchar();

        system("clear");
        string username2 = getUsernameFromConsole();

        while (username1 == username2) {
            system("clear");
            cout << "Username already taken! Please choose another username" << endl;
            username2 = getUsernameFromConsole();
        }
        
        system("clear");
        Board board2 = createBoardFromUserInput();
        system("clear");
        cout << username2 << " has been initialized!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();

        UserPlayer player1 = UserPlayer(board2, username1);
        UserPlayer player2 = UserPlayer(board1, username2);

        system("clear");
        if (rand() % 2 == 0) {
            cout << username1 << " will start first! Pass the computer to them" << endl;
            currentPlayer = &player1;
            waitingPlayer = &player2;
        } else {
            cout << username2 << " will start first! Pass the computer to them" << endl;
            currentPlayer = &player2;
            waitingPlayer = &player1;
        }

        cout << "Press enter to continue...";
        getchar();
        system("clear");

        while (loser == nullptr) {
            ShotResult result;
            
            do {
                result = currentPlayer->makeMove();

                if (currentPlayer->getOpponentBoard().getNumberShipSpotsLeft() == 0) {
                    if (currentPlayer == &player1) {
                        cout << player1.getUsername();
                        loser = &player2;
                    } else {
                        cout << player2.getUsername();
                        loser = &player1;
                    }
                    cout << " has won the game!" << endl;
                    break;
                }

                if (loser) {
                    break;
                }

                system("clear");
                
                switch (result) {
                    case SUNK:
                        cout << "Ship sunk! Make another move" << endl;
                        break;
                    case SHOT_HIT:
                        cout << "Hit! Make another move" << endl;
                        break;
                    case SHOT_MISS:
                        currentPlayer->getOpponentBoard().displayBoard(true);
                        cout << "Miss!" << endl;
                        break;
                }
            } while (result != SHOT_MISS);
            
            cout << "Pass the computer to ";

            if (currentPlayer == &player1) {
                cout << player2.getUsername() << endl;
            } else {
                cout << player1.getUsername() << endl;
            }

            cout << "Press enter to continue...";
            getchar();
            system("clear");

            Player* temp = currentPlayer;
            currentPlayer = waitingPlayer;
            waitingPlayer = temp;
        }
    }

    return 0;
};