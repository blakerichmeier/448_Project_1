//
//  Executive.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// Executive implementation
//

#include "myDefines.h"
#include <iostream>

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
    ability_fired = false;
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
	srand(time(NULL)); //randomize seed
    //new user game board
    GameBoard user1_gameBoard = GameBoard();
    GameBoard user2_gameBoard = GameBoard();
    //new state tracker
    game_state state = begin;
    game_winner who_won = playing;
    //user input object
    User_Input userInput;
	AI* computer;
	computer = new AI();
	bool vsAI = false; //keeps track of if we're playing an ai
	int difficulty; //ai difficulty
    
    //State Machine
    while (!winner) {
        switch (state) {
            case begin:
                //start the game
                // print banner
                cout << "Welcome to BattleShip" << endl;
                user1_gameBoard.printPlayBoard(true);
                state = set_ships;
				vsAI = userInput.checkVsAI();
				if(vsAI == true)
				{
					difficulty = userInput.aiDifficulty();
					computer->setDifficulty(difficulty);
				}
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
                        system("clear");
                        if(np == 0) {
                            user1_gameBoard.printShipBoard();
                        } else {
                            user2_gameBoard.printShipBoard();
                        }
                        cout << "\nPlayer " << np + 1 << endl;
                        cout << "Placing ship " << i  << " of " << userInput.getNumShips() << " ship(s)" << endl;
						if(vsAI == false) //ask both players for input if not playing ai
						{
							if ( i > 1) {
								userInput.getShipDir_Input();
							}
							userInput.getShip_Input();
                        }
						else
						{
							if(np == 0) //only ask player 1 for input when playing ai
							{
								if ( i > 1) 
								{
									userInput.getShipDir_Input();
								}
								userInput.getShip_Input();
							}
						}
						
                        if (np == 0) {
                            Ship ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
                            while(user1_gameBoard.check_if_occupied_positive(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col()) &&
                                  user1_gameBoard.check_if_occupied_negative(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col())) {
								system("clear");
                        		if(np == 0) {
                            		user1_gameBoard.printShipBoard();
                        		} else {
                            		user2_gameBoard.printShipBoard();
                        		}
								cout << "\nInvalid Input, please try again\n";
                                userInput.getShip_Input();
                                ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar());
                            }
                            if (user1_gameBoard.place_ship_return(ship_2_place, 0)) {
                                cout << "Ship " << i << " placed\n" << endl;
                            }
                        } 
						else if(vsAI == false) //place player 2's ships
						{
							Ship ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
							while(user2_gameBoard.check_if_occupied_positive(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col()) &&
                                  user2_gameBoard.check_if_occupied_negative(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col())) {
                        		if(np == 0) {
                            		user2_gameBoard.printShipBoard();
                        		} else {
                            		user2_gameBoard.printShipBoard();
                        		}
								cout << "\nInvalid Input, please try again\n";
								userInput.getShip_Input();
								ship_2_place = Ship(i, userInput.getColumn(),
                                                     userInput.getRow(),
                                                     userInput.getShipChar() );
							}
							if (user2_gameBoard.place_ship_return(ship_2_place, 0)) {
								cout << "Ship " << i << " placed\n" << endl;
							}
						}
						else //place ai's ships
						{
							int randCol = rand() % 10; //random column between 0 and 9
							int randRow = rand() % 9; //random row between 0 and 8
							int direcInt = rand() % 2; //random num, either 1 or 0 fir the randDirec[] index
							char randDirec[2] = {'v', 'h'};
							Ship ship_2_place = Ship(i, randCol, randRow, randDirec[direcInt]);
							while(user2_gameBoard.check_if_occupied_positive(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col()) &&
                                  user2_gameBoard.check_if_occupied_negative(ship_2_place,ship_2_place.get_row(),ship_2_place.get_col())) {
								//previous random position already had a ship, get a new one
								randCol = rand() % 9;
								randRow = rand() % 8;
								direcInt = rand() % 2;
								ship_2_place = Ship(i, randCol, randRow, randDirec[direcInt]);
							}
							if (user2_gameBoard.place_ship_return(ship_2_place, 0)) {
								cout << "Ship " << i << " placed\n" << endl;
							}
						}
                    } 
			//end for i
                    cout << endl;
                    //print ship board
                    if (np == 0) {
                        user1_gameBoard.printShipBoard();
			userInput.pause();
			cout << string(150, '\n');
			user1_gameBoard.printPlayBoard(false);
			
                    } else {
                        user2_gameBoard.printShipBoard();
			if(vsAI == false)
				userInput.pause();
			cout << string(150, '\n');
			user2_gameBoard.printPlayBoard(false);
			
                    }
                } //end for n
                //advance state machine
		cout << "\n\n\n ------------GAME PHASE-----------" << flush;                
		state = user1_turn;
		
                break;
                
            case user1_turn:
                //let player know what state
                cout << "\n################\nPlayer 1 Turn\n" << endl;
		user1_gameBoard.printPlayBoard(false);
		cout << "         ---Current Opponent Board---" << endl;
		cout << "\nYour turn!\n";
                //get turn input
				int special_ability;
				cout << "Would you like to use the special ability? (1 = yes, 2 = no)\n";
				cin >> special_ability;
				if (special_ability == 1 && !ability_fired) {
					user1_gameBoard.ability(userInput,user1_gameBoard.get_shipArr());
					ability_fired = true;
				}
				else if(ability_fired) {
					cout << "Ability already fired, firing a normal shot\n";
					userInput.getMove_Input();
				}
				else {
					userInput.getMove_Input();
				}

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
				userInput.pause();
				cout << string(40, '\n');
				break;
				} else {
					cout << "MOVE ERROR" << endl;
					break;
				}
                //test move
                
            case user2_turn:
                //let player know what state
		
                cout << "\n################\nPlayer 2 Turn\n" << endl;
		user2_gameBoard.printPlayBoard(false);
		cout << "         ---Current Opponent Board---" << endl;
		cout << "\nYour turn!\n";
                
                
				if(vsAI == false)
				{
					//get turn input
					int special_ability;
					cout << "Would you like to use the special ability? (1 = yes, 2 = no)\n";
					cin >> special_ability;
					if (special_ability == 1 && !ability_fired) {
						user2_gameBoard.ability(userInput,user2_gameBoard.get_shipArr());
						ability_fired = true;
					}
					else if(ability_fired) {
						cout << "Ability already fired, firing a normal shot\n";
						userInput.getMove_Input();
					}
					else {
						userInput.getMove_Input();
					}
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
				userInput.pause();
				cout << string(40, '\n');
						break;
					} else {
						cout << "MOVE ERROR" << endl;
						break;
					}
				}
				else
				{
					system("clear");
					int* guess = computer->aiMove(user1_gameBoard);
					if (user2_gameBoard.setGameSpace(guess[0], guess[1], user1_gameBoard.get_shipArr()))
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
				userInput.pause();
				cout << string(40, '\n');
						break;
					} else {
						cout << "MOVE ERROR" << endl;
						break;
					}
				}
                
            case end_game:
                string winOut;
                if (who_won == user_1) {
					if(vsAI == false)
						winOut = "Player 1";
					else
						winOut = "The player";
                } else {
					if(vsAI == false)
						winOut = "Player 2";
					else
						winOut = "The computer";
                }
                cout << winOut << " wins!" << endl;
                winner = true;
                break;
        } //end switch
    }
    //end game
}

void Executive::exitApp() {
    cout << "you just called exitApp() function" << endl;
}
