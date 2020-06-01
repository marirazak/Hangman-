#ifndef __BOARD_HPP__
#define __BOARD_HPP__
#include <iostream>
#include <string>

class Board{ //abstract base class for boards
public:
    Board(){};
    virtual void draw_board() = 0;
    
};

#endif
