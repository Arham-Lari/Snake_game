#pragma once
#include "raylib.h"
#include "snake.h"
#include "screen.h"
#include <utility>


class Game{

    public:
        Game();
        void draw();
        void movement();
        void foodAte();
        void reset();

    private:
        bool isPlayerAllowed ;
        Snake snake;
        void snakeCollide();
        std::pair<int, int> foodPos;
        Screen screen;
        bool timer(double);
        std::pair<int, int> foodGenerator();
        bool isTouchingBoundary();
};
