#pragma once
#include <vector>
class Snake{
    public:
        Snake();
        void draw();
        void moveDown();
        void moveUp();

    private:
        std::vector<std::pair<int, int>> snakebody;
        int cellsize;
        void move();
        float dx ;
        float dy;
};
