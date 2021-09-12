//
//  test_input.cpp
//
//  Created by Adam Abernathy on 9/11/21.
//

#include "test_input.hpp"

/*******************************************************************************
 **
 **MARK: Constructors
 **
 *******************************************************************************/

Test_Input::Test_Input() {
    move_row = 99;
    move_col = 99;
//    move_input = nullptr;
}

Test_Input::Test_Input(int p_row, int p_col) {
    move_row = p_row;
    move_col = p_col;
}

/*******************************************************************************
 **
 **MARK: Setter Methods
 **
 *******************************************************************************/
void Test_Input::setRow(int p_row) {
    move_row = p_row;
}

void Test_Input::setColumn(int p_col) {
    move_col = p_col;
}
/*******************************************************************************
 **
 **MARK: Getter Methods
 **
 *******************************************************************************/

int Test_Input::getRow() const{
    return move_row;
}

int Test_Input::getColumn() const{
    return move_col;
}
/*******************************************************************************
 **
 **MARK: Methods
 **
 *******************************************************************************/

int Test_Input::let_2_num(char convert) {
    switch (convert) {
        case ('A'):
            return 0;
        case ('B'):
            return 1;
        case ('C'):
            return 2;
        case ('D'):
            return 3;
        case ('E'):
            return 4;
        case ('F'):
            return 5;
        case ('G'):
            return 6;
        case ('H'):
            return 7;
        case ('I'):
            return 8;
        case ('J'):
            return 9;
        default:
            return 99;
    }
}

void Test_Input::get_input() {
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


