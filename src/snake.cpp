#include "snake.h"
#include <raylib.h>

Snake::Snake(){
    snakebody = {
        {5,5},
        {6,5},
        {7,5},
    };
    cellsize = 40;
}

void Snake::draw(){
    for(auto& eachBox : snakebody){
        DrawRectangle(eachBox.first * cellsize, eachBox.second, cellsize, cellsize, GREEN);
    }
}

void Snake::move(){
    for(int i = snakebody.size() - 1; i > 0;--i){
        snakebody[i].first = snakebody[i-1].first;
        snakebody[i].second = snakebody[i-1].second;

        if(i == 0){
            snakebody[i].first += dx;
            snakebody[i].second += dy;
        }
    }
}

void Snake::moveDown(){
    dy += 0.1f;
    dx = 0;
    move();
}

void Snake :: moveUp(){
    dy += 0.1f;
    dx = 0;
    move();
}
