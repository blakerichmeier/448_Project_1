//
//  Executive.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// Executive implementation
//

#include "myDefines.h"

#define NUM_PLAYERS 2
//FOR TESTING
#define TEST_SHIP_ID '2'
#define SHIP_LENGTH 3

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
    //new state tracker
    game_state state = begin;
    game_winner who_won = playing;
    //user input object
    User_Input userInput;
    
    //testing
    Test_Input testInput;
    
    //State Machine
    while (!winner) {
        switch (state) {
            case begin:
                //start the game
                // print banner
                cout << "Welcome to BattleShip" << endl;
                user1_gameBoard.printPlayBoard(true);
                state = set_ships;
                break;
            case set_ships:
                //user decides how many ships to play with
                userInput.getNumShips_Input();
                for (int np = 0; np<NUM_PLAYERS; np++){
                    //get & place users ships
                    for(int i=1; i <= userInput.getNumShips(); i++) {
                        cout << "Player " << np + 1 << endl;
                        cout << "Placing ship " << i  << " of " << userInput.getNumShips() << " ships" << endl;
                        userInput.getShipDir_Input();
                        userInput.getShip_Input();
                        
                        if (np == 0) {
                            Ship ship_2_place = Ship(TEST_SHIP_ID, i,
                                                     userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
                            //TODO: maybe add error check here
                            if (user1_gameBoard.place_ship_return(ship_2_place)) {
                                cout << "Ship " << i << " placed" << endl;
                            }
                        } else {
                            Ship ship_2_place = Ship(TEST_SHIP_ID, i,
                                                     userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
                            if (user2_gameBoard.place_ship_return(ship_2_place)) {
                                cout << "Ship " << i << " placed" << endl;
                            }
                        }
                    } //end for i
                    cout << endl;
                    //print ship board
                    if (np == 0) {
                        user1_gameBoard.printShipBoard();
                    } else {
                        user2_gameBoard.printShipBoard();
                    }
                } //end for n
                //TODO: do we want a whole board or keep track of the spots in the ship class?
                //advance state machine
                state = user1_turn;
                break;
                
            case user1_turn:
                //let player know what state
                cout << "Player 1 Turn" << endl;
                //get turn input
                userInput.getMove_Input();
                //testing
//                testInput.get_input();
                //test move
                if (user1_gameBoard.setGameSpace(userInput.getRow(), userInput.getColumn())) {
                    cout << "MOVE MADE" << endl;
                    //advance state
                    user1_gameBoard.printPlayBoard(false);
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
                //let player know what state
                cout << "Player 1 Turn" << endl;
                //get turn input
                userInput.getMove_Input();
                // test move
                if (user2_gameBoard.setGameSpace(userInput.getRow(), userInput.getColumn())) {
                    cout << "MOVE MADE";
                    user2_gameBoard.printPlayBoard(false);
                }
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
