//
// @author Michael Talaga
//
//
// ship.cpp

#include "myDefines.h"


using namespace std;


Ship::Ship(int s_len, int s_col, int s_row, char s_dir) {
    length = s_len;
    startCol = s_col;
    startRow = s_row;
    direction = s_dir;
    
}

void Ship::set_length(int len) {length = len;}

void Ship::set_row(int r) {startRow = r;}


void Ship::set_col(int c) {startCol = c;}

void Ship::set_direction(char dir) {direction = dir;}

int Ship::get_length()const{return length;}

int Ship::get_row()const{return startRow;}

int Ship::get_col()const{return startCol;}

char Ship::get_direction()const { return direction; };




/**
Methods
*/



		
