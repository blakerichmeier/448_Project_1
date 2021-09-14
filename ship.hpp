//
//
// @author Michael Talaga
//
// ship.hpp
//
// Ship object

#pragma once


#include<vector>
#include "myDefines.h"


using namespace std;

class Ship {
    
	private:
		int length; //Length of the ship determines which ship it is
		int startCol; //First x coordinate (Converted from A-J)
		int startRow; //First y coordinate
		int numHits; //Times ship has been hit (will need to prevent hitting same spot)
		//TODO: wouldn't it be easier to have a bool isHorizontal.  if true, ship horizontal, false vertical
		char direction; //starting direction:"Vertical" or "horizontal"
		bool sunken; //True if it has been sunk
		//std::vector<Coordinate> coordinates;//vector of ship coords

	public:
		/** with param
 		@pre none
 		@post ship object constructor with parameters
 		@param s_len length or size of ship
 		@param s_col starting x coordinate (seen as a letter and may take as char)
 		@param s_row starting y coordinate
 		@param s_dir direction represented as a char */
		Ship(int s_len, int s_col, int s_row, char s_dir);

		/*MARK: Setters*/
		/** Set length of ship object
		@pre none
		@post lenght becomes input
		@param len ship length */
		void set_length(int len);

		/** set first (starting) y coordinate
		@pre none
		@post startRow becomes input
		@param r starting y coord as an int */
		void set_row(int r);

		/** set first (starting) x coordinate
		@pre none
		@post startCol becomes input
		@param c starting x coord as an int */
		void set_col(int c);

		/** set direction of ship
		@pre none
		@post s_direction becomes input
		@param dir direction represented as a v or h, horizontal or vertical respectivly */
		void set_direction(char dir);


		/*MARK: Getters*/
		/** returns the id of the ship
		 @pre none
		 @post none
		 @return id as a char */
		int get_id() const;


		/** returns size of ship object
		 @pre none
		 @post none
		 @return Length of boat as an int */
		int get_length()const;

		/** return Starting x coord
		 @pre none
		 @post none
		 @return first x coord as a char */
		int get_col()const;

		/** return Starting y coord
		 @pre none
		 @post none
		 @return first y coord as an int */
		int get_row()const;


		/** return direction of the ship
		 @pre none
		 @post none
		 @return direction as a char */
		char get_direction()const;

		//Get # of times ship has been hit
		int get_hits();
    
		/*MARK: Methods*/
		//TODO: can be removed, can parse gameBoard or track there
		/** Adds a hit to object in increments of one
		@pre none
		@post none */
		void hit();

        //TODO: can be removed, can parse gameBoard or track there
		/** Returns whether or not the ship has sunk
		@pre none
		@post none
		@return true if ship has sunk, false else */
		bool isSunken();
};
