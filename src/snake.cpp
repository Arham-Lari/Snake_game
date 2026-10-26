#include "snake.h"
#include <iostream>
#include <raylib.h>

Snake::Snake(){
    snakebody = {
        {8,5},
        {9,5},
        {10,5},
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
    if(dy != 0) return;
    dy = 1;
    dx = 0;
}

void Snake :: moveUp(){
    if(dy != 0) return;
    dy = -1;
    dx = 0;
}

void Snake::moveLeft(){
    if(dx != 0) return;
    dx = -1;
    dy = 0;
}

void Snake::moveRight(){
    if(dx != 0) return;
    dx = 1;
    dy = 0;
}

bool Snake::isColliding(int x, int y){
    
    if(snakebody[0].first == x && snakebody[0].second == y){
        std::cout<<"the snake has collided";
        return true;
    } 

    return false;
}

void Snake::increaseSnakeLength(){
   snakebody.push_back({snakebody[snakebody.size() - 1].first, snakebody[snakebody.size() -1].second }); 
}
