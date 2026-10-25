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

    private:
        Screen sc ;
        int cellsize;
        float dx ;
        float dy;
};
