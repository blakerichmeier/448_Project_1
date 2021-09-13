//
//  cpu_player.cpp
//  448_project_1
//
//  Created by Adam Abernathy on 9/13/21.
//

#include "myDefines.h"

using namespace std;

/*******************************************************************************
 **
 **MARK: Constructors
 **
 ******************************************************************************/

CPUPlayer::CPUPlayer() {
    num_ships = 4;
    lastMove = "00";
    
}

CPUPlayer::CPUPlayer(int p_ships) {
    num_ships = p_ships;
    lastMove = "00";
}

/*******************************************************************************
 **
 **MARK: Destructor
 **
 ******************************************************************************/

/*******************************************************************************
 **
 **MARK: Setter Methods
 **
 ******************************************************************************/

void CPUPlayer::setNumShips(int p_ships) {
    num_ships = p_ships;
}

void CPUPlayer::setLastMove(string p_move) {
    lastMove = p_move;
}

/*******************************************************************************
 **
 **MARK: Getter Methods
 **
 ******************************************************************************/

int CPUPlayer::getNumShips() const{
    return num_ships;
}

string CPUPlayer::getLastMove() const{
    return lastMove;
}

/*******************************************************************************
 **
 **MARK: Methods
 **
 ******************************************************************************/
