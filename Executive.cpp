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
    GameBoard user1_gameBoard = GameBoard();
    GameBoard user2_gameBoard = GameBoard();
    //new state tracker
    game_state state = begin;
    game_winner who_won = playing;
    //user input object
    User_Input userInput;
    
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
                user1_gameBoard.set_ships(userInput.getNumShips());
                user2_gameBoard.set_ships(userInput.getNumShips());
                user1_gameBoard.set_totalHits(userInput.getNumShips());
                user2_gameBoard.set_totalHits(userInput.getNumShips());
                for (int np = 0; np<NUM_PLAYERS; np++){
                    //get & place users ships
                    for(int i=1; i <= userInput.getNumShips(); i++) {
                        cout << "----------------\nPlayer " << np + 1 << endl;
                        cout << "Placing ship " << i  << " of " << userInput.getNumShips() << " ships" << endl;
                        if ( i > 1) {
                            userInput.getShipDir_Input();
                        }
                        userInput.getShip_Input();
                        
                        if (np == 0) {
                            Ship ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
                            //TODO: maybe add error check here
                            if (user1_gameBoard.place_ship_return(ship_2_place, 0)) {
                                cout << "Ship " << i << " placed\n" << endl;
                            }
                        } else {
                            Ship ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
                            if (user2_gameBoard.place_ship_return(ship_2_place, 0)) {
                                cout << "Ship " << i << " placed\n" << endl;
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
                //advance state machine
		cout << "\n\n\n ------------GAME PHASE-----------" << endl;                
		state = user1_turn;
		
                break;
                
            case user1_turn:
                //let player know what state
                cout << "\n################\nPlayer 1 Turn" << endl;
                //get turn input
                userInput.getMove_Input();
                //test move
                if (user1_gameBoard.setGameSpace(userInput.getRow(), userInput.getColumn(),
                                                 user2_gameBoard.get_shipArr()))
                {
                    cout << "MOVE MADE" << endl;
                    //print board
                    user1_gameBoard.printPlayBoard(false);
                    //winner check & advance state
                    if (user1_gameBoard.check_winner()){
                        state = end_game;
                        who_won = user_1;
                    } else {
                        state = user2_turn;
                    }
                    break;
                } else {
                    cout << "MOVE ERROR" << endl;
                    break;
                }
                
            case user2_turn:
                //let player know what state
                cout << "\n################\nPlayer 2 Turn" << endl;
                //get turn input
                userInput.getMove_Input();
                // test move
                if (user2_gameBoard.setGameSpace(userInput.getRow(), userInput.getColumn(),
                                                 user1_gameBoard.get_shipArr()))
                {
                    cout << "MOVE MADE";
                    user2_gameBoard.printPlayBoard(false);
                    //winner check & advance state
                    if (user2_gameBoard.check_winner()){
                        state = end_game;
                        who_won = user_2;
                    } else {
                        state = user1_turn;
                    }
                    break;
                } else {
                    cout << "MOVE ERROR" << endl;
                    break;
                }
                
            case end_game:
                string winOut;
                if (who_won == user_1) {
                    winOut = "1";
                } else {
                    winOut = "2";
                }
                cout << "Player " << winOut << " Won!" << endl;
                winner = true;
                break;
        } //end switch
    }
    
    //end game
}

void Executive::exitApp() {
    cout << "you just called exitApp() function" << endl;
    //future use
}
