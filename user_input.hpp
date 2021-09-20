//
//  user_input.hpp
//  448_project_1
//
//  Created by Adam Abernathy on 9/13/21.
//

#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include <stdio.h>

class User_Input {
    
private:
    int move_row;
    int move_col;
    int ship_size;
    bool ship_horiz_dir;
    char ship_dir_char;
    int num_ships;
    
public:
    /*MARK: Constructors*/
    //default
    User_Input();
    
    /*MARK: Destructor*/
    /*none*/
    
    /*MARK: Setters*/
    /**
     @pre none
     @post assign move_row */
    void setRow(int p_row);
    
    /**
     @pre none
     @post assign move_col */
    void setColumn(int p_col);
    
    /**
     @pre none
     @post assign ship_size */
    void setShipSize(int p_size);
    
    /**
     @pre none
     @post assign ship_dir_char */
    void setShipChar(char p_char);
    
    /**
     @pre none
     @post assign ship_horiz_dir */
    void setMoveDir(bool p_dir);
    
    /**
     @pre
     @post assign num_ships
     @param p_ships number of ships in game
     */
    void setNumShips(int p_ships);
    
    /*MARK: Getters*/
    /**
     @pre
     @return row input */
    int getRow() const;
    
    /**
     @pre
     @return column input */
    int getColumn() const;
    
    /**
     @pre
     @return size input */
    int getShipSize() const;
    
    /**
     @pre none
     @post assign ship_dir_char */
    char getShipChar() const;
    
    /**
     @pre
     @return direction input */
    bool getMoveDir() const;
    
    /**
     @pre
     @return num_ships
     */
    int getNumShips() const;
    
    /*MARK: Methods*/
    /**
     @pre
     @post */
    int let_2_num(char convert);

    int domainCheck(string convert);
    
    /** prompts user for an input to set a ship
     @pre
     @post */
    void getShip_Input();
    
    void getShipDir_Input();
    
    /** prompts user for an input to make a move
     @pre
     @post */
    void getMove_Input();
    
    /**
     @pre
     @post
     */
    void getNumShips_Input();
    
    /** "erases" previous inputs */

    /** Pauses game until a letter is typed
    @pre
    @post */
    void pause();
    
};

#endif /* USER_INPUT_HPP */
