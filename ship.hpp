//
// 
// @author Michael Talaga
//
// ship.hpp
// 
// Ship object

#pragma once

#include "coordinate.hpp"
#include<vector>
#include "myDefines.h"


using namespace std;

class Ship{
	


	private:
		char id;
		int length; //Length of the ship determines which ship it is
		int startRow; //First x coordinate
		int startCol; //First y coordinate
		int numHits; //Times ship has been hit (will need to prevent hitting same spot)
		char direction; //starting direction:"Vertical" or "horizontal"
		bool sunken; //True if it has been sunk
		std::vector<Coordinate> coordinates;//vector of ship coords
		
		
	 /** with param
		@pre none
		@post ship object constructor with parameters
		@param s_len length or size of ship
		@param s_col starting x coordinate (seen as a letter and may take as char)
		@param s_row starting y coordinate
		@param s_direction direction represented as a char*/

	public:
		Ship(char s_id, int s_len, int s_col, int s_row, char s_dir){
		}

		
		//Destructor


		/*MARK: Setters*/
		/** Set length of ship object
		@pre none
		@post s_len becomes input
		@param size of ship as int */
		void set_length(int len);

		/** set first (starting) y coordinate
		@pre none
		@post s_row becomes input
		@param starting y coord as an int */
		void set_row(int r); //set x coord

		/** set first (starting) x coordinate
		@pre none
		@post s_col becomes input
		@param starting x coord as an int */
		void set_col(int c); 

		/** set direction of ship
		@pre none
		@post s_direction becomes input
		@param direction represented as a v or h (horizontal and vertical) */
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
		 @return first x coord as an int */
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

		/** Adds a hit to object in increments of one 
		@pre none
		@post none
		@param coordinate*/
		void hit();

		/** Returns whether or not the ship has sunk
		@pre none
		@post none
		@return bool if ship has sunk (true)*/
		bool isSunken();

		/** Creates coordinates and adds them to internal coordinate array
		@pre none
		@post none
		@return coordinate array for the ship based on direction and size*/
		vector<Coordinate> create_coords(int len, int x_coord, int y_coord);

		/** Removes a coordinate from the vector
		@pre none
		@post none
		@param Either the element of the vector or desired coordinate
		@return returns updated vector*/
		//void remove_coord(vector<Coordinate> coords, int element); 

		
		/** Prints current coordinate vector
		@pre none
		@post none
		@param updated coordinate vector*/
		void print_coords(vector<Coordinate> coords);
		
		
		
		//coordinate array
		
		


		
};
