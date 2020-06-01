#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"

class emptyboard : public Board{
public:
    std::string size;
    emptyboard(std::string word):Board(), size(word){}
    //    virtual void draw_board();
    std::vector<std::string> hold;
    
    //draws empty board with number of blanks based on chosen word	
    void draw_board(){
        std::string c = " _ ";
        for(int i = 0; i < size.size(); i++){
            hold.push_back(c);
        }
        for(int i = 0; i < size.size(); i++){
            std::cout << hold.at(i);
        }
        
    }
   
    //returnng number of blanks	 
    std::vector<std::string> returnvec(){
        return hold;
    }
    
    
};
