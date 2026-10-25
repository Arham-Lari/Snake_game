#include "snake.h"
#include <raylib.h>

Snake::Snake(){
    snakebody = {
        {5,5},
        {6,5},
        {7,5},
    };
    cellsize = 40;
    dx = 0;
    dy = 0;
}

void Snake::draw(){
    for(auto& eachBox : snakebody){
        DrawRectangle(eachBox.first * cellsize, eachBox.second * cellsize, cellsize, cellsize, GREEN);
    }
}

void Snake::move(){

    if(snakebody.empty()) return;

    for(int i = snakebody.size() - 1; i >= 0;--i){
        if(i == 0){
            snakebody[0].first += dx;
            snakebody[0].second += dy;
            return;
        }

        snakebody[i].first = snakebody[i-1].first;
        snakebody[i].second = snakebody[i-1].second;

    }
}

void Snake::moveDown(){
    dy = 1;
    dx = 0;
    move();
}

void Snake :: moveUp(){
    dy = -1;
    dx = 0;
    move();
}

void Snake::moveLeft(){
   dx = -1;
   dy = 0;
   move();
}

void Snake::moveRight(){
    dx = 1;
    dy = 0;
    move();
}
