#pragma once
#include "snake.h"
#include "screen.h"


class Game{

    public:
        Game();
        void draw();
        void movement();

    private:
        Snake snake;
        Screen screen;
        bool timer(double);
        bool isTouchingBoundary();
};
