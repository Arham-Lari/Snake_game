#include "snake.h"
#include <raylib.h>

Snake::Snake(){
    snakebody = {
        {5,5},
    };
    cellsize = 40;
}

void Snake::draw(){
    move();
   for(auto& eachBox : snakebody){
       DrawRectangle(eachBox.first * cellsize, eachBox.second, cellsize, cellsize, GREEN);
   }
}

void Snake::move(){
    for(auto& eachbox : snakebody){
        eachbox.first += dx;
        eachbox.second += dy;
    }
}

void Snake::moveDown(){
   dy += 0.1f;
   dx = 0;
}

void Snake :: moveUp(){
    dy += 0.1f;
    dx = 0;
}
