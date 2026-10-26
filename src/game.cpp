#include "game.h"
#include "screen.h"
#include "snake.h"
#include <cstdlib>
#include <raylib.h>
#include <utility>

Game::Game(){
  screen = Screen();
  snake = Snake();
  foodPos = foodGenerator();
}

void Game::draw(){
  screen.draw();
  snake.draw();

  DrawRectangle(foodPos.first * 40, foodPos.second * 40, 40, 40, RED);
  
}

void Game::movement(){

        if(timer(0.15)){
            if(isTouchingBoundary()) return;
            foodAte();
            snake.move();
        }

        if(IsKeyDown(KEY_S)){
            snake.moveDown();
        }
        
        if(IsKeyDown(KEY_W)){
            snake.moveUp();
        }

        if(IsKeyDown(KEY_A)){
            snake.moveLeft();
        }
        if(IsKeyDown(KEY_D)){
            snake.moveRight();
        }
}

bool Game::timer(double interval){
    static double curr_time = 0;
    double time = GetTime();

    if(time - curr_time >= interval){

        curr_time = time;
        return true;

    }

    return false;
}


bool Game::isTouchingBoundary(){

    for(auto& part : snake.snakebody) 
        if(!screen.insideBondary(part.second, part.first)){
            return true;
        }

  return false;
}
std::pair<int, int> Game::foodGenerator()
{
    int col = screen.col;
    int row = screen.row;

    return { (rand()%(col / 1) *1),(rand()%(row / 1) * 1)};
}

void Game::foodAte(){
   
    if(snake.isColliding(foodPos.first, foodPos.second)){
        foodPos = foodGenerator();
        snake.increaseSnakeLength();
    }
}
