#include "snake.h"
#include <cstddef>
#include <raylib.h>

Snake::Snake(){
    snakebody = {
        {15,5},
        {16,5},
        {17,5},
    };
    cellsize = 40;
    dx = -1;
    dy = 0;
}

void Snake::draw(){
    for(auto& eachBox : snakebody){
        DrawRectangle(eachBox.first * cellsize, eachBox.second * cellsize, cellsize, cellsize, GREEN);
    }
}

void Snake::move(){

    if(snakebody.empty()) return;

    for(int i = static_cast<int>(snakebody.size()) -1; i >0 ; --i){
        snakebody[i] = snakebody[i-1];  
    }

    snakebody[0].first += dx;
    snakebody[0].second += dy;
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
        return true;
    } 

    return false;
}

void Snake::increaseSnakeLength(){
   snakebody.push_back({snakebody[snakebody.size() - 1].first, snakebody[snakebody.size() -1].second }); 
}

bool Snake::snakeBodyCollision(){
    if(snakebody.size() < 3) return false;

    for(std::size_t i = 1; i < snakebody.size() ; ++i){
        if(snakebody[0] == snakebody[i]){
            return true;
        }
    }
   return false;
}

void Snake::reset(){
    snakebody = {
        {15,5},
        {16,5},
        {17,5},
    };
    dx = -1;
    dy = 0;
}
