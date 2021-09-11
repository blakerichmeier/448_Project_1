//
//  Executive.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// Executive implementation
//

#include "myDefines.h"

//macros
using namespace std;

/*******************************************************************************
**
**MARK: Constructors
**
*******************************************************************************/
//default
Executive::Executive() {

    winner = false;

}

/*******************************************************************************
**
**MARK: Setter Methods
**
*******************************************************************************/

/*NONE*/

/*******************************************************************************
**
**MARK: Getter Methods
**
*******************************************************************************/

/*NONE*/

/*******************************************************************************
**
**MARK: Methods
**
*******************************************************************************/

void Executive::runApp() {
    //new game board
    GameBoard gameBoard;
    //new user
    //new comp player
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
                cout << "start game" << endl;
                state = set_ships;
                break;
            case set_ships:
                //user set ships

                //comp set ships

                //print board
                gameBoard.printBoard();
                //advance state machine
                state = user_turn;
                break;

            case user_turn:
                //user interaction
                //testing
                testInput.get_input();
                gameBoard.setGameSpace(testInput.getRow(), testInput.getColumn(), gameBoard.get_arr());
                //advance state
                gameBoard.printBoard();
                if (check_winner()){
                    state = end_game;
                    who_won = user;
                } else {
                    state = cpu_turn;
                }
                break;

            case cpu_turn:
                //cpu random pick
                //could add some look at previous turn for hit here or in a cpu class

                //advance state
                if (check_winner()){
                    state = end_game;
                    who_won = cpu;
                } else {
                    state = user_turn;
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
