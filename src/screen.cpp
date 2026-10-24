#include "screen.h"
#include <raylib.h>


void Screen::draw(){
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col ; j++){
            DrawRectangle(j * cell_size, i * cell_size, cell_size, cell_size, BLACK);
        }
    }
}


void Screen::displayGrid(){
    for(auto& row : grid){
        for(auto& col : row){
            std::cout<<col;
        }
        std::cout<<std::endl;
    }
}

bool Screen::insideBondary(int&a , int&b){
    if(a > row || a<0  || b > col || b < 0){
       return false;
    }
    return true;
}


