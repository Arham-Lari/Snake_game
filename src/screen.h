#pragma once
#include <iostream>
#include <vector>
class Screen
{
    public:
        Screen(int width, int hight) 
            : row(hight/10) , col(width/20) ,cell_size(20), grid(row, std::vector<int>(col,0)) {}
        void draw();
        void displayGrid();

    private:
        int row;
        int col ;
        int cell_size;
        std::vector<std::vector<int>> grid;
};
