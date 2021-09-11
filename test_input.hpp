//
//  test_input.hpp
//
//  Created by Adam Abernathy on 9/11/21.
//

#ifndef TEST_INPUT_HPP
#define TEST_INPUT_HPP

#include "myDefines.h"

using namespace::std;

class Test_Input {
private:
    string move_input;
    int move_row;
    int move_col;
    
public:
    /*MARK: Constructors*/
    Test_Input();
    /**
     @pre
     @post */
    
    /*MARK: Destructor*/
    /*MARK: Setters*/
    void setRow(int p_row);
    void setColumn(int p_col);
    /*MARK: Getters*/
    int getRow() const;
    int getColumn() const;
    /*MARK: Methods*/
    int let_2_num(char convert);
    string get_input();
    int user_row (string input_string);
    int user_col(string input_string);
    
};

#endif /* TEST_INPUT_HPP */
