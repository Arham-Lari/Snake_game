#pragma once
#include "screen.h"
#include <vector>
class Snake{
    public:
        Snake();
        void draw();
        void move();
        void moveUp();
        void moveLeft();
        void moveRight();
        void moveDown();
        std::vector<std::pair<int, int>> snakebody;
        bool isColliding(int x ,int y);
        void increaseSnakeLength();
        bool snakeBodyCollision();
        void reset();

    private:
        Screen sc ;
        int cellsize;
        float dx ;
        float dy;
};
