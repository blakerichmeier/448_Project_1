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
        case ('A' | 'a'):
            return 0;
        case ('B' | 'b'):
            return 1;
        case ('C' | 'c'):
            return 2;
        case ('D' | 'd'):
            return 3;
        case ('E' | 'e'):
            return 4;
        case ('F' | 'f'):
            return 5;
        case ('G' | 'g'):
            return 6;
        case ('H' | 'h'):
            return 7;
        case ('I' | 'i'):
            return 8;
        case ('J' | 'j'):
            return 9;
        default:
            return 99;
    }
}

void Test_Input::get_input() {
    string user_input;
    //ask user for input
    cout << "Please enter a move, first row then column. Rows: A-J, Columns: 1-9" << endl;
    cin >> user_input;
    //set inputs
    setRow(let_2_num(user_input[0]));
    setColumn(user_input[1]);
}


