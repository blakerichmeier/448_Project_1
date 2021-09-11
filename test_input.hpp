//
//  test_input.hpp
//
//  Created by Adam Abernathy on 9/11/21.
//

#ifndef TEST_INPUT_HPP
#define TEST_INPUT_HPP

#include "myDefines.h"

using namespace std;

class Test_Input {
private:
//    string move_input;
    int move_row;
    int move_col;
    
public:
    /*MARK: Constructors*/
    Test_Input();
    /**
     @pre
     @post */
    Test_Input(int p_row, int p_col);
    
    /*MARK: Destructor*/
    
    /*MARK: Setters*/
    void setRow(int p_row);
    void setColumn(int p_col);
    /*MARK: Getters*/
    int getRow() const;
    int getColumn() const;
    
    /*MARK: Methods*/
    int let_2_num(char convert);
    void get_input();
    
};

#endif /* TEST_INPUT_HPP */
