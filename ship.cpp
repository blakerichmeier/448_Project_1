//
// @author Michael Talaga
//
//
// ship.cpp

#include "myDefines.h"


using namespace std;


Ship::Ship(char s_id, int s_len, int s_col, int s_row, char s_dir){
			id = s_id;
			length = s_len;
			startCol = s_col;
			startRow = s_row;
			direction = s_dir;
			//std::vector<Coordinate> coordinates = create_coords(s_len, s_col, s_row);
			sunken = false;
}



void Ship::set_length(int len) {length = len;}

void Ship::set_row(int r) {startRow = r;}


void Ship::set_col(int c) {startCol = c;}

void Ship::set_direction(char dir) {direction = dir;}

int Ship::get_id()const {return id;}

int Ship::get_length()const{return length;}

int Ship::get_row()const{return startRow;}

int Ship::get_col()const{return startCol;}

char Ship::get_direction()const { return direction; };

int Ship::get_hits() { return numHits; };


/**
Methods

*/

void Ship::hit() {
	numHits += 1;
	//isSunken();
}


bool Ship::isSunken() {
	if (numHits >= length) {
		sunken = true;
	}
	//sunken = true;
	return sunken;
}
		/**
		vector<Coordinate> Ship::create_coords(int len, int x_coord, int y_coord) {

			std::vector<Coordinate> coords(len);
			if (get_direction() == 'v') {
				for (int i = 0; i < len; i++) {
					Coordinate coord = Coordinate(x_coord, (y_coord - i)); //
					coords[i] = coord;
				}
			}
			else if (get_direction() == 'h') {
				for (int i = 0; i < len; i++) {
					Coordinate coord = Coordinate((x_coord - i), y_coord); //
					coords[i] = coord;
				}
			}

			return coords;
		}

		vector<Coordinate> Ship::remove_coord(vector<Coordinate> coords, int element) {
			// erase
			//
			return new_coords;
		}

		vector print_coords(vector<Coordinate> coords) {
			for (int i = 0; i < coords.size(); i++) {
				cout << coords[i] << "\n"end1;
			}
		}
		*/
