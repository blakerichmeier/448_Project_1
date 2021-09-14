//
//  user_input.cpp
//
//  Created by Adam Abernathy on 9/13/21.
//

#include "myDefines.h"

/*******************************************************************************
 **
 **MARK: Constructors
 **
 ******************************************************************************/

User_Input::User_Input() {
    move_row = 99;
    move_col = 99;
    ship_size = 99;
    ship_horiz_dir = true;
    
}

/*******************************************************************************
 **
 **MARK: Setter Methods
 **
 ******************************************************************************/
void User_Input::setRow(int p_row) {
    move_row = p_row;
}

void User_Input::setColumn(int p_col) {
    move_col = p_col;
}

void User_Input::setShipSize(int p_size) {
    ship_size = p_size;
}

void User_Input::setMoveDir(bool p_dir) {
    ship_horiz_dir = p_dir;
}
    
/*******************************************************************************
 **
 **MARK: Getter Methods
 **
 ******************************************************************************/

int User_Input::getRow() const{
    return move_row;
}

int User_Input::getColumn() const{
    return move_col;
}
    
int User_Input::getShipSize() const {
    return ship_size;
}

bool User_Input::getMoveDir() const{
    return ship_horiz_dir;
}
/*******************************************************************************
 **
 **MARK: Methods
 **
 ******************************************************************************/

int User_Input::let_2_num(char convert) {
    int i = 99;
    RESTART:
    if ('a' == convert || 'A' == convert) {
        i = 0;
    } else if ('b' == convert || 'B' == convert) {
        i = 1;
    } else if ('c' == convert || 'C' == convert) {
        i = 2;
    } else if ('d' == convert || 'D' == convert) {
        i = 3;
    } else if ('e' == convert || 'E' == convert) {
        i = 4;
    } else if ('F' == convert || 'f' == convert) {
        i = 5;
    } else if ('g' == convert || 'G' == convert) {
        i = 6;
    } else if ('h' == convert || 'H' == convert) {
        i = 7;
    } else if ('i' == convert || 'I' == convert) {
        i = 8;
    } else if ('j' == convert || 'J' == convert) {
        i = 9;
    } else {
        cout << "Please enter a letter between A-J" << endl;
        cin >> convert;
        goto RESTART;
    }
    return i;
}

void User_Input::getShipInput() {
    string user_input;
    char move[3];
    //ask user for input
    cout << "Please enter row of ship start, 1-9" << endl;
    cin >> user_input;
    move[0] = stoi(user_input);
    cout << "Please enter a column, A-J" << endl;
    cin >> user_input;
    move[1] = user_input[0];
    //set inputs
    setRow(move[0] - 1);
    setColumn(let_2_num(move[1]));
}

void User_Input::getShipDir_Input() {
    string input;
    cout << "Is ship horizontal or vertical? 1 = Horizontal, 0 = Vertical" << endl;
    cin >> input;
    //TODO: try catch here
    if (stoi(input)) {
        ship_horiz_dir = true;
    } else {
        ship_horiz_dir = false;
    }
}


void User_Input::getMoveInput() {
    string user_input;
    char move[3];
    //ask user for input
    cout << "Please enter row of shot, 1-9" << endl;
    cin >> user_input;
    move[0] = stoi(user_input);
    cout << "Please enter a column, A-J" << endl;
    cin >> user_input;
    move[1] = user_input[0];
    //set inputs
    setRow(move[0] - 1);
    setColumn(let_2_num(move[1]));
}

char User_Input::bool_2_char(bool convert) {
    if (convert) {
        return 'h';
    } else {
        return 'v';
    }
}


