#include "game.h"
#include "screen.h"
#include "snake.h"

Game::Game(){
  screen = Screen();
  snake = Snake();
}

void Game::draw(){
  screen.draw();
  snake.draw();
}

void Game::movement(){

        if(timer(0.15)){
            if(isTouchingBoundary()) return;
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
