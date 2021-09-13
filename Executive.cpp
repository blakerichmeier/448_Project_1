//
//  Executive.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// Executive implementation
//

#include "myDefines.h"
#include "gameBoard.hpp"

//macros
using namespace std;

/*******************************************************************************
 **
 **MARK: Constructors
 **
 ******************************************************************************/
//default
Executive::Executive() {
    
    winner = false;
    
}

/*******************************************************************************
 **
 **MARK: Setter Methods
 **
 ******************************************************************************/

/*NONE*/

/*******************************************************************************
 **
 **MARK: Getter Methods
 **
 ******************************************************************************/

/*NONE*/

/*******************************************************************************
 **
 **MARK: Methods
 **
 ******************************************************************************/

void Executive::runApp() {
    //new user game board
    GameBoard user1_gameBoard;
    GameBoard user2_gameBoard;
    //new user 1
    Player user1;
    //new user 2
    Player user2;
    //new state tracker
    game_state state = begin;
    game_winner who_won = playing;
    
    //testing
    Test_Input testInput;
    
    //State Machine
    while (!winner) {
        switch (state) {
            case begin:
                //start the game
                // print banner
                cout << "Welcome to BattleShip" << endl;
                user1_gameBoard.printBoard(true);
                state = set_ships;
                break;
            case set_ships:
                //user decides how many ships to play with
                int numShips;
                cout << "Enter number of ships to play with: ";
                cin >> numShips;
                cout << endl;
                while (numShips < 1 || numShips > 6)
                {
                    if (numShips < 1 || numShips >> 6)
                    {
                        cout << "Enter number of ships to play with: ";
                        cin >> numShips;
                        cout << endl;
                    }
                }
                user1_gameBoard.set_ships(numShips);
                //user set ships
                for(int i=1; i <= numShips; i++){
                    char x_input;
                    int x_coord;
                    int y_coord;
                    char dir;
                    char name = static_cast<char>(i);
                    while((y_coord < 1 || y_coord > 9) || (dir != 'v' && dir != 'h') || (x_coord < 0 || x_coord > 9 )){
                        cout << "Ship placement for ship #" << i  << endl;
                        
                        cout << "Please choose an x coordinate (A-J): ";
                        cin >> x_input;
                        cout << "Please choose a y coordinate (1-9): ";
                        cin >> y_coord;
                        cout << "Please choose a direction (v for vertical or h for horizontal) ";
                        cin >> dir;
                        cout << endl;
                        
                        x_coord = testInput.let_2_num(x_input);
                    }
                    
                    
                    //Ship ship = Ship(name, i, x_coord, y_coord, dir);
                    //place ship
                    user1_gameBoard.place_ship(y_coord-1, x_coord, i, dir);
                    user1_gameBoard.printBoard(true);
                    
                    dir = 'z';
                    
                    
                }
                //user2 set ships
                
                //print ship board
                //TODO: do we want a whole board or keep track of the spots in the ship class?
                //advance state machine
                state = user1_turn;
                break;
                
            case user1_turn:
                //get turn input
                //testing
                testInput.get_input();
                //test move
                if (user1_gameBoard.setGameSpace(testInput.getRow(), testInput.getColumn())) {
                    cout << "MOVE MADE" << endl;
                    //advance state
                    user1_gameBoard.printBoard(false);
                } else {
                    cout << "MOVE ERROR" << endl;
                }
                //winner check& advance state
                if (check_winner()){
                    state = end_game;
                    who_won = user_1;
                } else {
                    state = user2_turn;
                }
                break;
                
            case user2_turn:
                //get turn input
                
                //winner check & advance state
                if (check_winner()){
                    state = end_game;
                    who_won = user_2;
                } else {
                    state = user1_turn;
                }
                break;
                
            case end_game:
                winner = true;
                //troubleshooting
                cout << "game won" << endl;
                break;
                //should never reach default
            default:
                break;
        }
    }
    
    
    //end game
    
}

void Executive::exitApp() {
    cout << "you just called exitApp() function" << endl;
    //future use
}

bool Executive::check_winner() {
    //TODO: proto winner check
    
    return true;
}
