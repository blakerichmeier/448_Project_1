
//
//  gameBoard.cpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// game board implemntation
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

//with param
GameBoard::GameBoard(int p_rows, int p_cols, int n_ships) {
    num_rows = p_rows;
    num_col = p_cols;
    num_ships = n_ships;

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
    //    char return_char = board_arr[p_row][p_col];
    //    return return_char;
    return &board_arr[p_row][p_col];
}

/*******************************************************************************
 **
 **MARK: Methods
 **
 *******************************************************************************/

void GameBoard::printBoard(bool inst) {
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

void GameBoard::printInstructions() {
    cout << "inst line 1" << endl;
    cout << "inst line 2" << endl;
}

void GameBoard::printLegend() {
    cout << "       ************* LEGEND ************" << endl;
    cout << "       X => HIT  O => MISS  ? => UNKNOWN" << endl;
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

bool GameBoard::setGameSpace(int p_row, int p_col) {
    bool set_result = false;
    //check for a previous move
    if (isValidMove(board_arr[p_row][p_col])){
        //check for ship & set space
        if (!isShipHere()){
            board_arr[p_row][p_col] = 'X';
        } else {
            board_arr[p_row][p_col] = 'O';
        }
        set_result = true;
    } else {
        //TODO: throw error here or flag and alert user
        // have something like this already in test input class
    }
    return set_result;
}

bool GameBoard::isValidMove(char test_char) {
    bool move_valid = false;
    //has move been made?
    if (test_char == ' '){
        move_valid = true;
    }
    return move_valid;
}

// Work in progress
void GameBoard::place_ship(int ship_row, int ship_col, int ship_size, char direction) {
	if (direction == 'h' || direction == 'H')
	{
		for (int i = 0; i < ship_size; i++)
		{
			ship_arr[ship_row][ship_col+i] = 'S';
		}
	}
	else if (direction == 'v' || direction == 'V')
	{
		for (int j = 0; j < ship_size; j++)
		{
			ship_arr[ship_row+j][ship_col] = 'S';
		}
	}
}


//TODO: finish proto
bool GameBoard::place_ship_return(Ship p_ship) {
    for (int i = 0; i < p_ship.get_length(); i++) {
        //TODO: catch case when not enough room to place ship
        if (p_ship.get_direction() == 'v') {
            ship_arr[p_ship.get_row() - i][p_ship.get_col()] = 'S';
        } else {
            ship_arr[p_ship.get_row()][p_ship.get_col() + i] = 'S';
        }
        
    }
    //TODO: make recursive to use this bool
    return true;
}
