//
//  gameBoard.hpp
//
//  Created by Adam Abernathy on sept 8 2021
//  Copyright © 2021 Adam Abernathy. All rights reserved.
//
// game board for battleship game
//
//

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "myDefines.h"
#include "ship.hpp"

using namespace std;

class GameBoard {

private:
    int num_rows;//number of board rows
    int num_col; //number of board columns
    int num_ships; //number of ships used in game
    char **board_arr; //will hold the state of the current board
    char **ship_arr;//holds placed ships
    //array of letters used for the column header labels and ? to fill new board
    char col_head[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', ' '};

public:
    /*MARK: Constructors*/
    /** default constructor
     @pre none
     @post GameBoard object */
    GameBoard();

    /** with param
    @pre none
    @post GameBoard object with passed params
    @param p_rows number of rows
    @param p_cols number of columns
     @param n_ships number of ships in game */
    GameBoard(int p_rows, int p_cols, int n_ships);

    /*MARK: Destructor*/
    /** deletes array of pointers
     @pre need a GameBoard object
     @post deleted GameBoard object */
    ~GameBoard();

    /*MARK: Setters*/
    /**
    @pre none
    @post num_row is set to passed value
    @param row # of rows for map */
    void set_rows(int row);

    /**
    @pre none
    @post num_col is set to passed value
    @param col # of columns */
    void set_col(int col);

    /**
    @pre none
    @post num_ships is assigned passed value
     @param n_ship # of ships */
    void set_ships(int n_ship);

    /*MARK: Getters*/
    /**
     @pre none
     @post return the set num of rows */
    int get_rows() const;

    /**
     @pre none
     @returns num of columns */
    int get_col() const;

    /**
     @pre none
     @return num of ships */
    int get_ships() const;

    /**
     @pre none
     @param p_row row of desired position
     @param p_col column of desired position
     @return pointer to the char in the position */
    char* get_char(int p_row, int p_col);

    /*MARK: Methods*/

    /**
     @pre class object with rows and columns
     @post board printed on screen
     @param inst true = will print the instructions,
                 false = no instructions printed */
    void printPlayBoard(bool inst);
    
    /**
     @pre none
     @post outputs ship board to console */
    void printShipBoard();

    /**
    @pre none
    @post outputs instructions */
    void printInstructions();

    /**
    @pre none
    @post output legend */
    void printLegend();

    /**
     @pre none
     @post array passed is printed
     @param arr 2D array of the game*/
    void print_play(char **arr);

    /** prints the row header
     @pre none
     @post none */
    void printHeader();

    /**
     @pre none
     @post prints dotted line that matched game board lenght */
    void printDotted();

    /** set a space on the board, ie it changes the value to a hit or miss
     @pre none
     @post space is set to hit or miss
     @param p_row row of desired position
     @param p_col column od desired position
     @return true if sucess, false else */
    bool setGameSpace(int p_row, int p_col);

    /** checks char passed for previous move, ie is there a '?' in space passed
     @pre none
     @post none
     @param test_char char used in comparison
     @return true if '?' occupies the space passed, false else */
    bool isValidMove(char test_char);

    //for testing, havent seen ship class yet
    bool isShipHere(){return false;};

    /**
     @author
     @pre col and row chosen for ship placement
     @post
     @param ship_row of desired position
     @param ship_col column of desired ship placement
     @param ship_size size of ship
     @param direction direction of ship */
    void place_ship(int ship_row, int ship_col, int ship_size, char direction);
    
    /** place ships in ship_arr
     @pre none
     @post ship_arr is populated with ship passed
     @param p_ship Ship object
     @return true if ship is placed, false else */
    bool place_ship_return(Ship p_ship);
};

#endif /* GAMEBOARD_HPP */
