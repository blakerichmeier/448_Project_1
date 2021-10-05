//
//  Executive.hpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// Executive class that user interacts with and runs the app
//

#ifndef EXECUTIVE_HPP
#define EXECUTIVE_HPP

#include "myDefines.h"

using namespace std;

class Executive {

private:
    //used to throw state machine loop
    int turns = 0;
    int p1Hits = 0;
    int p1Misses = 0;
    int p2Hits = 0;
    int p2Misses = 0;
    bool winner;
    enum game_winner {user_1, user_2, playing};
    //state machine
    enum game_state {begin, set_ships, user1_turn, user2_turn, end_game };
    bool ability_fired;
    bool ability_fired2;

public:

    /*MARK: Constructors*/
    //default
    Executive();

    /*MARK: Setters*/
    /*NONE*/

    /*MARK: Getters*/
    /*NONE*/

    /*MARK: Methods*/
    /** main method that controls the app
     @pre none
     @post game has run, winner declared */
    void runApp();

    //prints a message. future useability
    void exitApp();

};

#endif /* EXECUTIVE_HPP */
