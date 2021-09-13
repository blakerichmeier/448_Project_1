//
//  cpu_player.hpp
//  448_project_1
//
//  Created by Adam Abernathy on 9/13/21.
//

#ifndef CPU_PLAYER_HPP
#define CPU_PLAYER_HPP

#include "myDefines.h"

using namespace std;

class CPUPlayer {
private:
    int num_ships;
    string lastMove; //previous move
//    Ship cpu_ships[6]; // array of cpu ships
    
public:
    /*MARK: Constructors*/
    /** default
     @pre none
     @post CPUPlayer object */
    CPUPlayer();
    
    /** with param
     @pre none
     @post CPUPlayer object with params passed */
    CPUPlayer(int p_ships);
    
    /*MARK: Destructor*/
    //TODO: make destructor
    
    /*MARK: Setters*/
    /**
     @pre none
     @post num_ships assigned value passed */
    void setNumShips(int p_ships);
    
    /**
     @pre none
     @post lastMove set to string passed */
    void setLastMove(string p_move);

    /*MARK: Getters*/
    /**
     @pre
     @retun value assigned to num_ships */
    int getNumShips() const;
    
    /**
     @pre
     @return the previous move made */
    string getLastMove() const;
    /*MARK: Methods*/
    /** initiate cpu move
     @pre
     @post */
    
    /** check previous move for a hit
     @pre none
     @post*/
    
};

#endif /* CPU_PLAYER_HPP */
