

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
    ship_dir_char = 'h';
    num_ships = 0;

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

void User_Input::setShipChar(char p_char) {
    ship_dir_char = p_char;
}

void User_Input::setMoveDir(bool p_dir) {
    ship_horiz_dir = p_dir;
}

void User_Input::setNumShips(int p_ships) {
    num_ships = p_ships;
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

int User_Input::getShipSize() const{
    return ship_size;
}

char User_Input::getShipChar() const{
    return ship_dir_char;
}

bool User_Input::getMoveDir() const{
    return ship_horiz_dir;
}

int User_Input::getNumShips() const{
    return num_ships;
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

void User_Input::getShip_Input() {
    string user_input;
    char move[3];
    //ask user for input
    cout << "Please enter a column, A-J" << endl;
    cin >> user_input;
    move[1] = user_input[0];
    cout << "Please enter row of ship start, 1-9" << endl;
    cin >> user_input;
    move[0] = stoi(user_input);
    //set inputs
    setRow(move[0] - 1);
    setColumn(let_2_num(move[1]));
}

void User_Input::getShipDir_Input() {
    string input;
    cout << "Please choose a direction (v for vertical or h for horizontal): ";
    cin >> input;
    
    try{
      if (input[0] == 'h' || input[0] == 'H') {
        ship_horiz_dir = true;
        ship_dir_char = input[0];
      }
      else if (input[0] == 'v' || input[0] == 'V'){
        ship_horiz_dir = false;
        ship_dir_char = 'v';
      }
      else {
	 throw input;
	 cout << "Input error\n";
	}
    }
    catch (...){
      cout << "Try that again.\n";
      getShipDir_Input(); 
}
}

void User_Input::getMove_Input() {
    string user_input;
    char move[3];
    //ask user for input
    cout << "Please enter a column, A-J" << endl;
    cin >> user_input;
    move[1] = user_input[0];
    //set column
    setColumn(let_2_num(move[1]));
    
    CHECKPOINT:
    try{
       cout << "Please enter row of shot, 1-9" << endl;
       cin >> user_input;
       //TODO: error here
       int attempt = stoi(user_input);
       if (attempt > 0 && attempt <10){
          move[0] = attempt;
       }
       else{ throw (user_input); }
       }
	catch(...){
	cout <<"Please try again with a number between 1-9\n";
	goto CHECKPOINT;
	}
    //set inputs
    setRow(move[0] - 1);
    
}

void User_Input::getNumShips_Input() {
    int numShips;
    //ask user for number of ships
    cout << "Enter number of ships to play with: ";
    cin >> numShips;
    cout << endl;
    while (numShips < 1 || numShips > 6)
    {
        //if wrong number of ships is inputted
        if (numShips < 1 || numShips >> 6)
        {
            cout << "Enter number of ships to play with: ";
            cin >> numShips;
            cout << endl;
        }
    }
    num_ships = numShips;

}
