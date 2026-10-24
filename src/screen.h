#pragma once
#include <iostream>
#include <ratio>
#include <vector>
class Screen
{
    public:
        Screen(int width, int hight)
            : row(hight/40),col(width/40),cell_size(40),grid(row,std::vector<int>(col,0)) {};
        void draw();
        void displayGrid();
        bool insideBondary(int& r, int& c);

    private:
        int row;
        int col ;
        int cell_size;
        std::vector<std::vector<int>> grid;
};
