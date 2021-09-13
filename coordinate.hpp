//
// @author Michael Talaga
//
// coordinate.hpp

#include "myDefines.h"
using namespace std;

class Coordinate {

private:
	int x; //x coord
	int y; //y coord (represented as A-J which may be converted)



/** with param
	@pre none
	@post Creates a coordinate constructor to be used as a position on the board
	@param x coord
	@param y coord
	*/
public:
	Coordinate(int x_coord, int y_coord);


};
