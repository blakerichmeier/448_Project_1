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
     @post assign isHorizontal */
    void setMoveDir(bool p_dir);
    
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
     @pre
     @return direction input */
    bool getMoveDir() const;
    
    /*MARK: Methods*/
    /**
     @pre
     @post */
    int let_2_num(char convert);
    
    /** prompts user for an input to set a ship
     @pre
     @post */
    void getShipInput();
    
    void getShipDir_Input();
    
    /** prompts user for an input to make a move
     @pre
     @post */
    void getMoveInput();
    
    /** converts bool to 'h' or 'v'
     @pre none
     @post none
     @param convert ture = 'h', false = 'v'
     @return 'h' for horizontal, 'v' for vertical */
    char bool_2_char(bool convert);
    
};

#endif /* USER_INPUT_HPP */
