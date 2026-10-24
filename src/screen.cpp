#include "screen.h"
#include <iostream>
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


