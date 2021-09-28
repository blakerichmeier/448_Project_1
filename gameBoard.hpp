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
    int total_hits; //track total num hits to win
    int current_hits; //hits to point in the game to time sampled, external read only
    char **board_arr; //will hold the state of the current board
    char **ship_arr;//holds placed ships
    //array of letters used for the column header labels and ? to fill new board
    char col_head[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', ' '};
    bool is_up;
    bool is_right;

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
    
    /**
     @pre none
     @post total_hits is calculated by the ship scaling rules */
    void set_totalHits(int total_hits);

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
    
    /**
     @pre none
     @return total_hits */
    int get_totalHits() const;
    
    /**
     @pre none
     @return current hits in game */
    int get_currHits() const;
    
    /**
     @pre
     @return the ship_arr pointer */
    char **get_shipArr() const;

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
     @param arr ship board of opponet
     @return true if sucess, false else */
    bool setGameSpace(int p_row, int p_col, char **arr);

    /** checks char passed for previous move, ie is there a '?' in space passed
     @pre none
     @post none
     @param test_char char used in comparison
     @return true if ' ' occupies the space passed, false else */
    bool isValidMove(char test_char);

    //for testing, havent seen ship class yet
    bool isShipHere(){return false;};
    
    /** place ships in ship_arr, recursive
     @pre none
     @post ship_arr is populated with ship passed
     @param p_ship Ship object
     @param control recursive control
     @return true if ship is placed, false else */
    bool place_ship_return(Ship p_ship, int control);
    
    /** checks for winning conditions
     @pre a gameBoard object
     @post none
     @return true if winner, false else*/
    bool check_winner ();

    bool check_if_occupied_positive(Ship p_ship, int row,int col);
    bool check_if_occupied_negative(Ship p_ship, int row,int col);
    
};

#endif /* GAMEBOARD_HPP */
