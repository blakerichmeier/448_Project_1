
//
//  gameBoard.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// game board implementation
//

#include "myDefines.h"

//macros
using namespace std;

#define ROWS 9
#define COLUMNS 10
#define TEST_SHIPS 4

/*******************************************************************************
 **
 **MARK: Constructors
 **
*******************************************************************************/

//default
GameBoard::GameBoard() {
    num_rows = ROWS;
    num_col = COLUMNS;
    num_ships = TEST_SHIPS;
    total_hits = 0;
    current_hits = 0;
    is_up = false;
    is_right = false;

    board_arr = new char*[num_rows];

    for (int r = 0; r<ROWS; r++) {
        board_arr[r] = new char[COLUMNS];
        for (int c = 0; c<COLUMNS; c++){
            board_arr[r][c] = col_head[10];
        }
    }

    ship_arr = new char*[num_rows];

    for (int r = 0; r<ROWS; r++) {
        ship_arr[r] = new char[COLUMNS];
        for (int c = 0; c<COLUMNS; c++){
            ship_arr[r][c] = col_head[10];
        }
    }
}
//with parameters
GameBoard::GameBoard(int p_rows, int p_cols, int n_ships) {
    num_rows = p_rows;
    num_col = p_cols;
    num_ships = n_ships;
    total_hits = 0;
    current_hits = 0;

    board_arr = new char*[p_rows];

    for (int r = 0; r<p_rows; r++) {
        board_arr[r] = new char[p_cols];
        for (int c = 0; c<p_cols; c++){
            board_arr[r][c] = col_head[11];
        }
    }

    ship_arr = new char*[p_rows];

    for (int r = 0; r<p_rows; r++) {
        ship_arr[r] = new char[p_cols];
        for (int c = 0; c<p_cols; c++){
            ship_arr[r][c] = col_head[11];
        }
    }

}

/*******************************************************************************
 **
 **MARK: Destructor
 **
 *******************************************************************************/

GameBoard::~GameBoard() {
    if (board_arr != nullptr) {
        for (int r = 0; r<num_rows; r++) {
            delete board_arr[r];
        }
        delete [] board_arr;
    }
    board_arr = nullptr;

    if (ship_arr != nullptr) {
        for (int r = 0; r<num_rows; r++) {
            delete ship_arr[r];
        }
        delete [] ship_arr;
    }
    ship_arr = nullptr;
}

/*******************************************************************************
 **
 **MARK: Setter Methods
 **
 *******************************************************************************/

void GameBoard::set_rows(int row) {
    num_rows = row;
}

void GameBoard::set_col(int col) {
    num_col = col;
}

void GameBoard::set_ships(int n_ship) {
    num_ships = n_ship;
}

void GameBoard::set_totalHits(int total_ships) {
    for (int s = total_ships; s > 0; s--) {
        total_hits += s;
    }
}

/*******************************************************************************
 **
 **MARK: Getter Methods
 **
 *******************************************************************************/

int GameBoard::get_rows() const{
    return num_rows;
}

int GameBoard::get_col() const{
    return num_col;
}

int GameBoard::get_ships() const{
    return num_ships;
}

char* GameBoard::get_char(int p_row, int p_col) {
    return &board_arr[p_row][p_col];
}

int GameBoard::get_totalHits() const{
    return total_hits;
}

int GameBoard::get_currHits() const{
    return current_hits;
}

char** GameBoard::get_shipArr() const{
    return ship_arr;
}

/*******************************************************************************
 **
 **MARK: Methods
 **
 *******************************************************************************/

void GameBoard::printPlayBoard(bool inst) {
    if (inst) {
        printInstructions();
    }
    cout << endl;
    printLegend();
    printHeader();
    printDotted();
    print_play(board_arr);
    printHeader();
}

void GameBoard::printShipBoard() {
    printLegend();
    printHeader();
    printDotted();
    print_play(ship_arr);
    printHeader();
}

void GameBoard::printInstructions() {
    // cout << "inst line 1" << endl;
    // cout << "inst line 2" << endl;
}

void GameBoard::printLegend() {
    cout << "       ************* LEGEND ************" << endl;
    cout << "        X => HIT  O => MISS  S => SHIPS" << endl;
    cout << "       *********************************" << endl;
}

void GameBoard::print_play(char **arr) {
    for (int r = 0; r<num_rows; r++) {
        for (int c = 0; c<num_col; c++){
            if (c == num_col) {
                cout << arr[r][c];
                goto END;
            }
            if (c == 0) {
                cout << " " << r + 1 << " | " << arr[r][c];
            } else {
                cout << " | " << arr[r][c];
            }
        }
    END:
        cout << " | " << r + 1 << endl;
        printDotted();
    }
}

void GameBoard::printHeader() {
    for (int c = 0; c<num_col; c++) {
        if (c == num_col) {
            cout << col_head[c];
            goto END;
        }
        if (c == 0){
            cout << "   | " << col_head[c];
        } else {
            cout << " | " << col_head[c];
        }
    }
END:
    //satisfies compiler
    cout << " |   " << endl;
}

void GameBoard::printDotted() {
    for (int i = 0; i<num_col + 1; i++){
        if (i == num_col ) {
            cout << " --- -- ";
            goto END;
        }
        if (i == 0) {
            cout << " --";
        } else {
            cout << " ---";
        }
    }
END:
    cout << endl;
}

bool GameBoard::setGameSpace(int p_row, int p_col, char **arr) {
    if (board_arr[p_row][p_col] == ' ') {
        if (arr[p_row][p_col] == 'S') {
            board_arr[p_row][p_col] = 'X';
            current_hits++;
	    cout << "HIT" << endl;
            return true;
        } else if (arr[p_row][p_col] == ' ')  {
            board_arr[p_row][p_col] = 'O';
	    cout << "MISS" <<endl;
            return true;
        }
    }
    return false;
}

bool GameBoard::isValidMove(char test_char) {
    bool move_valid = false;
    //has move been made?
    if (test_char == ' '){
        move_valid = true;
    }
    return move_valid;
}

bool GameBoard::place_ship_return(Ship p_ship, int control) {
    if (control == p_ship.get_length()) {
        return true;
    }
    //if vertical option chosen
    if (p_ship.get_direction() == 'v') {
        //marks S on position
        if(is_up) {
            ship_arr[p_ship.get_row() - control][p_ship.get_col()] = 'S';
        } else {
            ship_arr[p_ship.get_row() + control][p_ship.get_col()] = 'S';
        }
        if (place_ship_return(p_ship, control+1)) {
            return true;
        }
    }
    //if horizontal option is chosen
    if (p_ship.get_direction() == 'h') {
        //marks S on position
        if(is_right) {
            ship_arr[p_ship.get_row()][p_ship.get_col() + control] = 'S';
        } else {
            ship_arr[p_ship.get_row()][p_ship.get_col() - control] = 'S';
        }
        
        if (place_ship_return(p_ship, control+1)) {
            return true;
        }
    }
    return false;
}

bool GameBoard::check_winner() {
    if (total_hits == current_hits) {
        return true;
    }
    return false;
}

bool GameBoard::check_if_occupied_positive(Ship p_ship,int row,int col) {
    for(int i = 0; i < p_ship.get_length(); i++) {
        if(p_ship.get_direction() == 'h' || p_ship.get_direction() == 'H') {
            if(col+i > 9) {
                is_right = false;
            } else {
                if(ship_arr[row][col+i] == 'S') {
                is_right = false;
                cout << "Invalid Input, please try again\n";
                return true;
                }
            }
        } else {
            if(row+i > 8) {
                is_up = true;
            } else {
                if(ship_arr[row+i][col] == 'S') {
                is_up = false;
                cout << "Invalid Input, please try again\n";
                return true;
                }
            }
        }
    }
    return false;
}

bool GameBoard::check_if_occupied_negative(Ship p_ship,int row,int col) {
    for(int i = 0; i < p_ship.get_length(); i++) {
        if(p_ship.get_direction() == 'h' || p_ship.get_direction() == 'H') {
            if(col-i < 0) {
                is_right = true;
            }
            if(ship_arr[row][col-i] == 'S') {
                is_right = false;
                cout << "Invalid Input, please try again\n";
                return true;
            }
        } else {
            if(row-i < 0) {
                is_up = false;
            }
            else if(ship_arr[row-i][col] == 'S') {
                is_up = true;
                cout << "Invalid Input, please try again\n";
                return true;
            }
        }
    }
    return false;
}
