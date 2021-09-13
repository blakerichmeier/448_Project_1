//
//  Player.hpp
//
//  Created by Adam Abernathy on 9/13/21.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "myDefines.h"

using namespace std;

class Player {
private:
public:
    /*MARK: Constructors*/
    Player();
    /*MARK: Destructor*/
    /*MARK: Setters*/
    /*MARK: Getters*/
    /*MARK: Methods*/
    /** prints the move made by player
     @pre
     @post */
    void printMove();
    
    /**
     @pre
     @post */
    void printShips();
    
    /**
     @pre
     @post */
    bool makeMove();
};

#endif /* PLAYER_HPP */
